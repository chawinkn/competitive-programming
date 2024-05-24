#include <bits/stdc++.h>
using namespace std;

int p[109], dist[109][109][2];
vector<pair<int,int>> g[109];
priority_queue<tuple<int,int,int,int>> pq;

int main() {
   	ios_base::sync_with_stdio(false); cin.tie(NULL);
   	int n;
   	cin >> n;
   	for (int i = 1; i <= n; i++) cin >> p[i];
   	int S, D, F, m;
   	cin >> S >> D >> F >> m;
   	while (m--) {
   		int u, v, w;
   		cin >> u >> v >> w;
   		g[u].push_back({v, w});
   		g[v].push_back({u, w});
	}
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= F; j++) 
			dist[i][j][0] = dist[i][j][1] = 1e9;
			
	dist[S][0][false] = 0;
	pq.push({0, S, 0, false});
	while (!pq.empty()) {
		auto [d,u,f,t]=pq.top(); pq.pop();
		if (f < F && dist[u][f][t]+p[u] < dist[u][f+1][t]) {
			dist[u][f+1][t] = dist[u][f][t]+p[u];
			pq.push({-dist[u][f+1][t], u, f+1, t});
		}
		if (!t && dist[u][f][t] < dist[u][F][true]) {
			dist[u][F][true] = dist[u][f][t];
			pq.push({-dist[u][F][true], u, F, true});
		}
		for (auto [v,w] : g[u]) {
			if (f >= w && dist[u][f][t] < dist[v][f-w][t]) {
				dist[v][f-w][t] = dist[u][f][t];
				pq.push({-dist[v][f-w][t], v, f-w, t});
			}
		}
	}
	cout << dist[D][F][true];
 	return 0;  	
}