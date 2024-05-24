#include <bits/stdc++.h>
using namespace std;

int p[109], visited[109][109][2];
vector<pair<int,int>> g[109];
vector<vector<vector<int>>> dist(109, vector<vector<int>>(109, vector<int>(2, 1e9)));
priority_queue<tuple<int,int,int,int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, S, D, F, a, b, w;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	cin >> S >> D >> F >> m;
	while (m--) {
		cin >> a >> b >> w;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	dist[S][0][0] = 0;
	pq.push({0, S, 0, 0});
	int ans=1e9;
	while (!pq.empty()) {
		auto [d, u, f, ticket]=pq.top(); pq.pop();
		d *= -1;
		if (u == D) ans = min(ans, d+(ticket ? p[u]*(F-f) : 0));
		if (visited[u][f][ticket]) continue;
		visited[u][f][ticket] = true;
		for (auto [v, w] : g[u]) {
			if (!ticket && d < dist[v][F-w][ticket+1]) {
				dist[v][F-w][ticket+1] = d;
				pq.push({-d, v, F-w, ticket+1});
			}
			for (int i = 0; i+f <= F; i++) {
				int now=i+f, cost=p[u]*i;
				if (now < w) continue;
				if (d+cost < dist[v][now-w][ticket]) {
					dist[v][now-w][ticket] = d+cost;
					pq.push({-(d+cost), v, now-w, ticket});
				}
			}
		}
	}
	cout << ans;
	return 0;
}