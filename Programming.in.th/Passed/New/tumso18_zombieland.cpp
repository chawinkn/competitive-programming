#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<pair<int,int>> g[200009];
vector<ll> dist(200009, 1e18), ans(200009, 1e18);
bool visited[200009];
priority_queue<pair<ll,int>> pq;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, s, e, u, v, w;
    cin >> n >> m >> s >> e;
    while (m--) {
    	cin >> u >> v >> w;
    	g[u].push_back({v, w});
    	g[v].push_back({u, w});
	}
	dist[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		auto [d,u]=pq.top(); pq.pop();
		if (visited[u]) continue;
		visited[u] = true;
		for (auto [v,w] : g[u]) {
			if (dist[u]+w < dist[v]) {
				dist[v] = dist[u]+w;
				pq.push({-dist[v], v});
			}
		}
	}
	memset(visited, false, sizeof(visited));
	q.push(e);
	ans[e] = 0;
	pq.push({0, e});
	while (!q.empty()) {
		auto u=q.front(); q.pop();
		if (visited[u]) continue;
		visited[u] = true;
		for (auto [v,w] : g[u]) {
			if (dist[v]+w == dist[u]) {
				q.push(v);
				ans[v] = 0;
				pq.push({0, v});
			}
		}
	}
	memset(visited, false, sizeof(visited));
	while (!pq.empty()) {
		auto [d,u]=pq.top(); pq.pop();
		if (visited[u]) continue;
		visited[u] = true;
		for (auto [v,w] : g[u]) {
			if (ans[u]+w < ans[v]) {
				ans[v] = ans[u]+w;
				pq.push({-ans[v], v});
			}
		}
	}
	int Q;
	cin >> Q;
	while (Q--) {
		cin >> u;
		cout << ans[u] << "\n";
	}
 	return 0;   
}