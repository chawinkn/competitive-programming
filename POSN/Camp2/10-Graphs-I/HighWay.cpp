#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, cnt[100009], W[100009];
vector<tuple<int,int,int>> g[100009];

ll dfs(int u, int p) {
	ll count=1;
	for (auto [v,w,i] : g[u]) {
		if (v == p) continue;
		ll res=dfs(v, u);
		cnt[i] = res*(n-res);
		count += res;
	}
	return count;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
    	ll u, v, w;
    	cin >> u >> v >> w;
    	g[u].push_back({v, w, i});
    	g[v].push_back({u, w, i});
    	W[i] = w;
	}
	dfs(0, -1);
	int k;
	ll sum=0;
	for (int i = 0; i < n-1; i++) sum += cnt[i]*W[i];
	cin >> k;
	while (k--) {
		ll e, z;
		cin >> e >> z;
		sum -= cnt[e]*W[e];
		sum += cnt[e]*z;
		W[e] = z;
		cout << sum << "\n";
	}
    return 0;
}