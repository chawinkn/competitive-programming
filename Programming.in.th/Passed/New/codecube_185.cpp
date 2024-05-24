#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long

vector<pair<ll,ll>> g[10009];
vector<vector<ll>> dist(10009, vector<ll>(8, LLONG_MAX));
priority_queue<pair<ll,pair<ll,ll>>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, m, t, x, y, u, v, w, k;
	cin >> n >> m >> t >> x >> y;
	while (m--) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
	dist[x][0] = 0;
	pq.push({dist[x][0], {x, 0}});
	while (!pq.empty()) {
		u=pq.top().s.f, k=pq.top().s.s; pq.pop();
		int kk=(k+1)%t;
		for (auto i : g[u]) {
			v=i.f, w=i.s;
			if (dist[u][k]+w < dist[v][kk]) {
				dist[v][kk] = dist[u][k]+w;
				pq.push({-dist[v][kk], {v, kk}});
			}
		}
	}
	if (dist[y][t-1] != LLONG_MAX) cout << dist[y][t-1];
	else cout << -1;
	return 0;
}
