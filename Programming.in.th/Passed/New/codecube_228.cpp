#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long

vector<pair<ll,ll>> g[100009];
vector<vector<ll>> dist(100009, vector<ll>(2, LLONG_MAX));
priority_queue<pair<ll,pair<ll,ll>>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, m, ticket, k, t, u, v, w;
	cin >> n >> m >> k >> t;
	while (m--) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dist[1][0] = dist[1][1] = 0;
	pq.push({dist[1][0], {1, 0}});
	while (!pq.empty()) {
		u=pq.top().s.f, ticket=pq.top().s.s; pq.pop();
		for (auto i : g[u]) {
			v=i.f, w=i.s;
			if (dist[u][ticket]+w < dist[v][ticket]) {
				dist[v][ticket] = dist[u][ticket]+w;
				pq.push({-dist[v][ticket], {v, ticket}});
			}
			if (!ticket && dist[u][ticket]+k < dist[v][ticket+1]) {
				dist[v][ticket+1] = dist[u][ticket]+k;
				pq.push({-dist[v][ticket+1], {v, ticket+1}});
			}
		}                             
	}
	ll ans=min(dist[n][0], dist[n][1]);
	if (ans <= t) cout << "Happy Winnie the Pooh :3\n" << ans;
	else cout << "No Honey TT";
	return 0;
}
