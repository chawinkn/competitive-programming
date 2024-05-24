#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<pair<int,int>> g[100009], dist(100009, {1e9, 0});
vector<bool> visited(100009, false);
priority_queue<pair<int,int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, s, t, u, v, w;
	cin >> n >> m >> s >> t;
	while (m--) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dist[s] = {0, -1};
	pq.push({dist[s].f, s});
	while (!pq.empty()) {
		u=pq.top().s; pq.pop();
		if (visited[u]) continue;
		visited[u] = true;
		for (auto i : g[u]) {
			v=i.f, w=i.s;
			if (dist[u].f+w < dist[v].f) {
				dist[v] = {dist[u].f+w, u};
				pq.push({-dist[v].f, v});
			}
		}
	}
	vector<int> ans;
	for (int i = t; i != -1; i=dist[i].s) ans.push_back(i);
	cout << dist[t].f << "\n" << ans.size() << "\n";
	for (int i = ans.size()-1; i >= 0; i--) cout << ans[i] << " ";
	return 0;
}
