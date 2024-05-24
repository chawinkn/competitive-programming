#include <bits/stdc++.h>
using namespace std;

#define ll long long

// 42/100 (after contest)

bool neighbor[100009], visited[100009];
vector<pair<int,int>> g[100009];
priority_queue<pair<int,int>> pq;
ll dist[100009], best[100009];

void dfs(int u, int p) {
	for (auto [v,w] : g[u]) {
		if (v == p) continue;
		dist[v] = max(dist[v], dist[u]+w);
		best[v] = max(best[v], dist[v]);
		dfs(v, u);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> neighbor[i];
	for (int i = 0; i < n-1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (neighbor[u] && !neighbor[v]) {
			g[u].push_back({v, w});
		}
		else if (neighbor[v] && !neighbor[u]) {
			g[v].push_back({u, w});
		}
		else if (!neighbor[u] && !neighbor[v]) {
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
	}
	for (int i = 0; i < n; i++) {
		if (neighbor[i]) {
			memset(dist, 0, sizeof(dist));
			dfs(i, i);
		}
	}
	while (q--) {
		int x;
		cin >> x;
		cout << best[x] << "\n";
	}
	return 0;
}