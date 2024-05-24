#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[10009];

int dfs(int u, int p) {
	int dist=0;
	for (auto [v,w] : g[u]) {
		if (v == p) continue;
		dist = max(dist, w+dfs(v, u));
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, sum=0;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
		sum += w;
	}
	cout << 2*sum-dfs(1, -1);
	return 0;
}