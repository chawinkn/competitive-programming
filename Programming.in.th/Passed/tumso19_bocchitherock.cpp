#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define V 100001

vector<pair<int,int>> g[100005];
vector<int> visited(100005), dist(100005, INT_MAX);
priority_queue<pair<int,int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k, u, v, w;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> v >> w;
		g[V].push_back({v, w});
	}
	
	dist[V] = 0;
	pq.push({-dist[V], V});
	while (!pq.empty()) {
		u = pq.top().s;
		pq.pop();
		if (visited[u]) continue;
		visited[u] = 1;
		
		for (auto i : g[u]) {
			v = i.f;
			w = i.s;
			if (!visited[v] && dist[u]+w < dist[v]) {
				dist[v] = dist[u]+w;
				pq.push({-dist[v], v});
			}
		}
	}
	cout << dist[0];
	return 0;
}
