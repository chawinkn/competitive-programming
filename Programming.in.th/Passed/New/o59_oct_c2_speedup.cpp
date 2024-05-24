#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<pair<ll,ll>> g[80009];
vector<vector<ll>> dist(80009, vector<ll>(9, 1e18));
bool potion[80009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, m, l, q, u, v, w;
	cin >> n >> m >> l >> q;
	while (m--) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
	while (l--) {
		cin >> u;
		potion[u] = true;
	}
	priority_queue<tuple<ll,ll,ll,ll>> pq;
	dist[1][0] = 0;
	pq.push({0, 1, 0, 0});
	while (!pq.empty()) {
		auto [d,u,p,k]=pq.top(); pq.pop();
		d *= -1;
		for (auto [v,w] : g[u]) {
			if (potion[u] && p != u && k < q && d+w/(1<<(k+1)) < dist[v][k+1]) {
				dist[v][k+1] = d+w/(1<<(k+1));
				pq.push({-dist[v][k+1], v, u, k+1});
			}	
			if (d+w/(1<<k) < dist[v][k]) {
				dist[v][k] = d+w/(1<<k);
				pq.push({-dist[v][k], v, p, k});
			}
		}
	}	
	ll ans=1e18;
	for (int i = 0; i <= q; i++) ans = min(ans, dist[n][i]);
	cout << ans;
	return 0;
}