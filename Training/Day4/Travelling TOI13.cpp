#include <bits/stdc++.h>
using namespace std;

// Shortest path

#define pii pair<int,int>

vector<pii> g[10009];
vector<int> dist1(10009, 1e9), dist2(10009, 1e9);
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra(int u, vector<int>& dist) {
	pq.push({dist[u]=0, u});
	while (!pq.empty()) {
		int u=pq.top().second; pq.pop();
		for (auto i : g[u]) {
			int v=i.first, w=i.second;
			if (dist[u]+w < dist[v]) {
				pq.push({dist[v]=dist[u]+w, v});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, x, y, z;
	cin >> n >> m >> x >> y >> z;
	while (m--) {
		int u, v, d;
		cin >> u >> v >> d;
		g[u].push_back({v, d});
		g[v].push_back({u, d});
	}
	dijkstra(x, dist1);
	dijkstra(y, dist2);
	int ans=0, mn=1e9;
	for (int i = 0; i < n; i++) {
		if (dist1[i] <= z && dist2[i] < mn) {
			mn = dist2[i];
			ans = i;
		}
	}
	cout << ans << " " << dist1[ans] << " " << dist2[ans];
	return 0;
}