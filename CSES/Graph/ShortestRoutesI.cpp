#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
#define ll long long
 
vector<pair<int,int>> g[100009];
vector<ll> dist(100009, 1e14);
int visited[100009];
 
int main() {
	ll n, m, a, b, c;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		g[a].push_back({b, c});
	}
	priority_queue<pair<ll,int>> pq;
	dist[1] = 0;
	pq.push({0, 1});
	while (!pq.empty()) {
		int u=pq.top().s;
		pq.pop();
		if (visited[u]) continue;
		visited[u] = 1;
		for (auto i : g[u]) {
			int v=i.f, w=i.s;
			if (dist[u]+w < dist[v]) {
				dist[v] = dist[u]+w;
				pq.push({-dist[v], v});
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << dist[i] << " ";
	return 0;
}
