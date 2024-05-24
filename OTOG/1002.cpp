#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>

vector<tuple<int,int,int>> g[100009];
bool visited[100009], bridge[200009];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int tin[100009], low[100009], timer;

void dfs(int u, int p) {
	visited[u] = true;
	tin[u] = low[u] = timer++;
	for (auto [v,w,i] : g[u]) {
		if (v == p) continue;
		if (visited[v]) {
			low[u] = min(low[u], tin[v]);
			continue;
		}
		dfs(v, u);
		low[u] = min(low[u], low[v]);
		if (low[v] > tin[u]) bridge[i] = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	vector<tuple<int,int,int>> E(m);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w, i});
		g[v].push_back({u, w, i});
		E[i] = {u, v, w};
	}
	timer = 0;
	memset(tin, -1, sizeof(tin));
	memset(low, -1, sizeof(low));
	for (int i = 0; i < n; i++) {
		if (!visited[i]) dfs(i, i);
	}
	for (int i = 0; i < n; i++) g[i].clear();
	for (int i = 0; i < m; i++) {
		if (bridge[i]) continue;
		auto [u,v,w] = E[i];
		g[u].push_back({v, w, i});
		g[v].push_back({u, w, i});
	}
	while (q--) {
		int s, t;
		cin >> s >> t;
		vector<ll> dist(n, 1e18); 
		pq.push({dist[s]=0, s});
		while (!pq.empty()) {
			auto [d,u]=pq.top(); pq.pop();
			for (auto [v,w,i] : g[u]) {
				if (dist[u]+w < dist[v]) {
					pq.push({dist[v]=dist[u]+w, v});
				}
			}
		}
		cout << (dist[t] != 1e18 ? dist[t] : -1) << "\n";
	}
	return 0;
}