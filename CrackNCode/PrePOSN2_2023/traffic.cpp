#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<tuple<int,int,int>> g[100009];
vector<ll> dist(100009, 1e18);
bool visited[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, e, u, v, w, f;
	cin >> n >> e;
	while (e--) {
		cin >> u >> v >> w >> f;
		g[u].push_back({v, w, f});
		g[v].push_back({u, w, f});
	}
	priority_queue<pair<ll,int>> pq;
	dist[1] = 0;
	pq.push({0, 1});
	while (!pq.empty()) {
		auto [d,u]=pq.top(); pq.pop();
		if (visited[u]) continue;
		visited[u] = true;
		for (auto [v,w,f] : g[u]) {
			ll weight=0, curr=dist[u], left=w;
			if (curr / f % 2 == 1) {
				weight += f - curr % f;	
			}
			else if (f - curr % f >= left) {
				weight += left;
				left = 0;
			}
			else {
				weight += f - curr % f + f;
				left -= f - curr % f;
			}
			weight += left / f * f * 2 + left % f;
			if (dist[u]+weight < dist[v]) {
				dist[v] = dist[u]+weight;
				pq.push({-dist[v], v});
			}
		}
	}
	cout << dist[n];
	return 0;
}
