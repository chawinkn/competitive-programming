#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<pair<int,int>> g[80009];
vector<int> dist;
bool visited[80009];

void dfs(int u) {
	visited[u] = true;
	for (auto [w,v] : g[u]) {
		if (visited[v]) continue;
		dist.push_back(w);
		dfs(v);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	ll l=1, r=0;
	for (int i = 1; i <= n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({w, v});
		g[v].push_back({w, u});
		r += w;
	}
	for (int i = 0; i <= n; i++) sort(g[i].begin(), g[i].end());
	for (int i = 0; i <= n; i++) {
		if (g[i].size() == 1) dfs(i);
	}
	while (l < r) {
		ll m=l+(r-l+1)/2, sum=0;
		int cnt=0;
		for (auto i : dist) {
			sum += i;
			if (sum >= m) {
				sum = 0;
				cnt++;
			}
		}
		if (cnt >= 3) l = m;
		else r = m-1;
	}
	cout << l;
	return 0;
}