#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[10009];
vector<int> dist1(10009, 1e9), dist2(10009, 1e9);
priority_queue<pair<int,int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, x, y, z;
	cin >> n >> m >> x >> y >> z;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dist1[x] = 0;
	pq.push({0, x});
	while (!pq.empty()) {
		auto [d,u]=pq.top(); pq.pop();
		for (auto [v,w] : g[u]) {
			if (dist1[u]+w < dist1[v]) {
				dist1[v] = dist1[u]+w;
				pq.push({-dist1[v], v});
			}
		}
	}
	dist2[y] = 0;
	pq.push({0, y});
	while (!pq.empty()) {
		auto [d,u]=pq.top(); pq.pop();
		for (auto [v,w] : g[u]) {
			if (dist2[u]+w < dist2[v]) {
				dist2[v] = dist2[u]+w;
				pq.push({-dist2[v], v});
			}
		}
	}
	int ans=0, mn=1e9;
	for (int i = 0; i < n; i++) {
		if (dist1[i] <= z && dist2[i] < mn) {
			ans = i;
			mn = dist2[i];
		}
	}
	cout << ans << " " << dist1[ans] << " " << dist2[ans];
	return 0;
}