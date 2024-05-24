#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long
 
ll s[1009];
priority_queue<pair<ll,pair<int,int>>> pq;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, m;
	ll u, v, w, best, k;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<pair<ll,ll>> g[1009];
		vector<vector<ll>> dist(1009, vector<ll>(1009, LLONG_MAX));
		while (m--) {
			cin >> u >> v >> w;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
		for (int i = 1; i <= n; i++) cin >> s[i];
		dist[1][s[1]] = 0;
		pq.push({0, {1, s[1]}});
		while (!pq.empty()) {
			u=pq.top().s.f, k=pq.top().s.s; pq.pop();
			for (auto i : g[u]) {
				v=i.f, w=i.s;
				int best=min(k, s[v]);
				if (dist[u][k]+w*k < dist[v][best]) {
					dist[v][best] = dist[u][k]+w*k;
					pq.push({-dist[v][best], {v, best}});
				}
			}
		} 
		ll ans=LLONG_MAX;
		for (int i = 1; i <= 1000; i++) ans = min(ans, dist[n][i]);
		cout << ans << "\n";
	}
	return 0;
}
