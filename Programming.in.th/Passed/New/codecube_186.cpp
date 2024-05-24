#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[100009];
int dist[100009];

void dfs(int u, int p) {
	for (auto [v,w] : g[u]) {
		if (v == p) continue;
		dist[v] = dist[u]^w;
		dfs(v, u);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n-1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dfs(1, -1);
	while (m--) {
		int u, v;
		cin >> u >> v;
		cout << (dist[u]^dist[v]) << "\n";
	}
	return 0;
}