#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[100009];
vector<vector<int>> dist(100009, vector<int>(9, 1e9));

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, K;
	cin >> n >> m >> K;
	while (m--) {
		int u, v, h;
		cin >> u >> v >> h;
		g[u].push_back({v, h});
	}
	priority_queue<tuple<int,int,int>> pq;
	dist[1][0] = 0;
	pq.push({0, 1, 0});
	while (!pq.empty()) {
		auto [d,u,k]=pq.top(); pq.pop();
		for (auto [v,h] : g[u]) {
			if (h < -100) {
				if (k < K && dist[u][k] < dist[v][k+1]) {
					dist[v][k+1] = dist[u][k];
					pq.push({-dist[v][k+1], v, k+1});
				}
				continue;
			}
			if (dist[u][k]+max(0, h) < dist[v][k]) {
				dist[v][k] = dist[u][k]+max(0, h);
				pq.push({-dist[v][k], v, k});
			}	
		}
	}
	int ans=1e9;
	for (int i = 0; i <= K; i++) ans = min(ans, dist[n][i]);
	cout << (ans != 1e9 ? ans : -1);
	return 0;
}