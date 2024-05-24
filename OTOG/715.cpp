#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[100009];
vector<vector<int>> dist(100009, vector<int>(5, 1e9));
priority_queue<tuple<int,int,int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k, a, b;
	cin >> n >> m >> k >> a >> b;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dist[a][k-1] = 0;
	pq.push({0, a, k-1});
	while (!pq.empty()) {
		auto [d,u,cnt]=pq.top(); pq.pop();
		for (auto [v,w] : g[u]) {
			if (dist[u][cnt]+w < dist[v][(cnt+1)%k]) {
				dist[v][(cnt+1)%k] = dist[u][cnt]+w;
				pq.push({-dist[v][(cnt+1)%k], v, (cnt+1)%k});
			}
		}
	}
	cout << dist[b][0];
	return 0;
}