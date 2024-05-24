#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g1[100009], g2[100009];
vector<int> dist1(100009, 1e9), dist2(100009, 1e9);
priority_queue<pair<int,int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, q, s, t;
	cin >> n >> m >> q >> s >> t;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		g1[u].push_back({v, w});
		g2[v].push_back({u, w});
	}
	dist1[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		auto [d,u]=pq.top(); pq.pop();
		for (auto [v,w] : g1[u]) {
			if (dist1[u]+w < dist1[v]) {
				dist1[v] = dist1[u]+w;
				pq.push({-dist1[v], v});
			}
		}
	}
	dist2[t] = 0;
	pq.push({0, t});
	while (!pq.empty()) {
		auto [d,u]=pq.top(); pq.pop();
		for (auto [v,w] : g2[u]) {
			if (dist2[u]+w < dist2[v]) {
				dist2[v] = dist2[u]+w;
				pq.push({-dist2[v], v});
			}
		}
	}
	while (q--) {
		int k;
		cin >> k;
		cout << dist1[k]+dist2[k] << "\n";
	}
	return 0;
}