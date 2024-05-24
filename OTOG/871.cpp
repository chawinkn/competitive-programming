#include <bits/stdc++.h>
using namespace std;

bool ingredient[50009], visited[50009][21];
vector<pair<int,int>> g[50009];
vector<vector<int>> dist(50009, vector<int>(21, 1e9));
priority_queue<tuple<int,int,int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, p, k;
	cin >> n >> m >> p >> k;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	while (p--) {
		int x;
		cin >> x;
		ingredient[x] = true;
	}
	int s;
	cin >> s;
	dist[s][0] = 0;
	pq.push({0, s, 0});
	while (!pq.empty()) {
		auto [d,u,cnt]=pq.top(); pq.pop();
		if (visited[u][cnt]) continue;
		visited[u][cnt] = true;
		for (auto [v,w] : g[u]) {
			if (dist[u][cnt]+w < dist[v][cnt]) {
				dist[v][cnt] = dist[u][cnt]+w;
				pq.push({-dist[v][cnt], v, cnt});
			}
			if (ingredient[u] && dist[u][cnt]+w < dist[v][cnt+1]) {
				dist[v][cnt+1] = dist[u][cnt]+w;
				pq.push({-dist[v][cnt+1], v, cnt+1});
			}
		}
	}
	if (dist[s][k] != 1e9) cout << dist[s][k];
	else cout << "NO FOOD :(";
	return 0;
}