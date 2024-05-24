#include <bits/stdc++.h>
using namespace std;

int e[100009];
vector<pair<int,int>> g[100009];
vector<int> dist(100009, 1e9);
bool visited[100009];
priority_queue<pair<int,int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, Q, X;
	cin >> n >> k >> Q >> X;
	for (int i = 1; i <= n; i++) cin >> e[i];
	while (k--) {
		int a, b;
		cin >> a >> b;
		g[a].push_back({b, e[b]});
	}
	dist[X] = e[X];
	pq.push({-dist[X], X});
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
	while (Q--) {
		int q;
		cin >> q;
		cout << dist[q] << "\n";
	}
	return 0;
}