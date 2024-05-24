#include <bits/stdc++.h>
using namespace std;

// Shortest path (MSSP, SSSP)
// 80/100 (TLE)

#define ll long long
#define T tuple<ll,int,int>

vector<pair<int,int>> g[100009];
priority_queue<T, vector<T>, greater<T>> pq;
vector<ll> distmor(100009, 1e18);
vector<vector<ll>> dist(100009, vector<ll>(19, 1e18));

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, a, k, s, e;
	cin >> n >> m >> a >> k >> s >> e;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for (int i = 1; i <= a; i++) {
		int x;
		cin >> x;
		pq.push(make_tuple(distmor[x]=0, x, 0));
	}
	while (!pq.empty()) {
		ll d; int u, pain;
		tie(d, u, pain) = pq.top(); pq.pop();
		for (auto i : g[u]) {
			int v=i.first, w=i.second;
			if (distmor[u]+w < distmor[v]) {
				pq.push(make_tuple(distmor[v]=distmor[u]+w, v, pain));
			}
		}
	}
	ll ans=1e18;
	pq.push(make_tuple(dist[s][0]=0, s, 0));
	while (!pq.empty()) {
		ll d; int u, pain;
		tie(d, u, pain) = pq.top(); pq.pop();
		if (u == e) {
			ans = min(ans, dist[u][pain]);
			continue;
		}
		if (dist[u][pain]+distmor[u] < dist[u][0]) {
			pq.push(make_tuple(dist[u][0]=dist[u][pain]+distmor[u], u, 0));
		}
		for (auto i : g[u]) {
			int v=i.first, w=i.second;
			if (pain < k && dist[u][pain]+w < dist[v][pain+1]) {
				pq.push(make_tuple(dist[v][pain+1]=dist[u][pain]+w, v, pain+1));
			}
		}
	}
	cout << ans;
	return 0;
}