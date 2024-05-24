#include <bits/stdc++.h>
using namespace std;

int G[20009], from[20009];
vector<pair<int,int>> g[20009];
vector<int> dist(20009, 1e9);
priority_queue<pair<int,int>> pq;
set<pair<int,int>> ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k, p;
	cin >> n >> m >> k >> p;
	for (int i = 1; i <= k; i++) cin >> G[i];
	for (int i = 1; i <= m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	memset(from, -1, sizeof(from));
	dist[p] = 0;
	pq.push({0, -p});
	while (!pq.empty()) {
		auto [d,u]=pq.top(); pq.pop();
		u *= -1; // idk why but with ascending (-,+) got 89/100 descending (-,-) got 100/100
		for (auto [v,w] : g[u]) {
			if (dist[u]+w < dist[v]) {
				dist[v] = dist[u]+w;
				from[v] = u;
				pq.push({-dist[v], -v});
			}
		}
	}
	for (int i = 1; i <= k; i++) cout << dist[G[i]] << " "; cout << "\n";
	for (int i = 1; i <= k; i++) {
		int u=G[i];
		while (from[u] != -1) {
			ans.insert({u, from[u]});
			u = from[u];
		}
	}
	cout << ans.size() << "\n";
	for (auto [u,v] : ans) cout << u << " " << v << "\n";
	return 0;
}