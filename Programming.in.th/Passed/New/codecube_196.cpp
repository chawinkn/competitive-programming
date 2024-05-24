#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<pair<int,int>> g[100009];
priority_queue<pair<ll,int>> pq;
queue<int> q;
vector<ll> dist1(100009, 1e18), dist2(100009, 1e18);
bool visited[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, u, v, w, a, b, c, d;
	cin >> n >> m;
	while (m--) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	cin >> a >> b >> c >> d;
	dist1[a] = 0;
	pq.push({0, a});
	while (!pq.empty()) {
		auto [d,u]=pq.top(); pq.pop();
		for (auto [v,w] : g[u]) {
			if (dist1[u]+w < dist1[v]) {
				dist1[v] = dist1[u]+w;
				pq.push({-dist1[v], v});
			}
		}
	}
	q.push(b);
	while (!q.empty()) {
		auto u=q.front(); q.pop();
		if (visited[u]) continue;
		visited[u] = true;
		for (auto [v,w] : g[u]) {
			if (dist1[u] == dist1[v]+w) q.push(v);
		}
	}
	if (!visited[c]) {
		dist2[c] = 0;
		pq.push({0, c});	
	}
	while (!pq.empty()) {
		auto [d,u]=pq.top(); pq.pop();
		for (auto [v,w] : g[u]) {
			if (!visited[v] && dist2[u]+w < dist2[v]) {
				dist2[v] = dist2[u]+w;
				pq.push({-dist2[v], v});
			}
		}
	}
	cout << (dist2[d] != 1e18 ? dist2[d] : -1);
	return 0;
}