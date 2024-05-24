#include <bits/stdc++.h>
using namespace std;

#define ll long long

int p[100009];
ll total=0, best=1e18, ans1, ans2;
vector<tuple<int,int,int>> e;
vector<pair<int,int>> g[100009];

int find(int u) {
	if (u == p[u]) return u;
	return p[u] = find(p[u]);
}

ll dfs(int u, int p) {
	ll sum = 0;
	for (auto [v,w] : g[u]) {
		if (v == p) continue;
		ll res = dfs(v, u);
		if (abs(res-total+res+w) < best) {
			best = abs(res-total+res+w);
			ans1 = res;
			ans2 = total-res-w;
		}
		sum += res+w;
	}
	return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) p[i] = i;
    while (m--) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	e.push_back({w, u, v});
	}
	sort(e.begin(), e.end());
	for (auto [w,u,v] : e) {
		if (find(u) == find(v)) continue;
		p[find(u)] = p[find(v)];
		total += w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dfs(0, -1);
	cout << total << "\n" << min(ans1, ans2) << " " << max(ans1, ans2);
 	return 0;   
}