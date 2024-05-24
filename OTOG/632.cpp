#include <bits/stdc++.h>
using namespace std;

#define T tuple<int,int,int,int>

int p[109], dist[109][109][3];
vector<pair<int,int>> g[109];
priority_queue<T, vector<T>, greater<T>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	int S, D, F, m;
	cin >> S >> D >> F >> m;
	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= F; j++) {
			dist[i][j][0] = dist[i][j][1] = 1e9;
		}
	}
	pq.push({dist[S][0][0]=0, S, 0, 0});
	while (!pq.empty()) {
		auto [d,u,f,t]=pq.top(); pq.pop();
		if (f+1 <= F && dist[u][f][t]+p[u] < dist[u][f+1][t]) {
			pq.push({dist[u][f+1][t]=dist[u][f][t]+p[u], u, f+1, t});
		}
		if (!t && dist[u][f][t] < dist[u][F][t+1]) {
			pq.push({dist[u][F][t+1]=dist[u][f][t], u, F, t+1});
		}
		for (auto [v,w] : g[u]) {
			if (f >= w && dist[u][f][t] < dist[v][f-w][t]) {
				pq.push({dist[v][f-w][t]=dist[u][f][t], v, f-w, t});
			}
		}
	}
	cout << dist[D][F][1];
	return 0;
}