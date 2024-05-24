#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[100009];
vector<int> dist1(100009, 1e9), dist2(100009, 1e9);
priority_queue<pair<int,int>> pq;

// 90/100

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, s, e;
	cin >> n >> m >> s >> e;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dist1[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		auto [d,u]=pq.top(); pq.pop();
		for (auto [v,w] : g[u]) {
			if (dist1[u]+w < dist1[v]) {
				dist1[v] = dist1[u]+w;
				pq.push({-dist1[v], v});
			}
		}
	}
	dist2[e] = 0;
	pq.push({0, e});
	while (!pq.empty()) {
		auto [d,u]=pq.top(); pq.pop();
		for (auto [v,w] : g[u]) {
			if (dist2[u]+w < dist2[v]) {
				dist2[v] = dist2[u]+w;
				pq.push({-dist2[v], v});
			}
		}
	}
	int ans=0;
	for (int i = 1; i <= n; i++) ans = max(ans, dist1[i]+dist2[i]);
	cout << ans;
	return 0;
}