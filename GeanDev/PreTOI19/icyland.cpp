#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<pair<int,int>> g[200009];
ll dist1[200009], dist2[200009], t[200009];

void dfs(int u, int p, ll dist[]) {
	for (auto [v,w] : g[u]) {
		if (v == p) continue;
		dist[v] = max(dist[v], dist[u]+w);
		dfs(v, u, dist);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n-1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for (int i = 1; i <= m; i++) cin >> t[i];

	ll mx=0; 
	int idx=1;
	dfs(1, 1, dist1);

	for (int i = 1; i <= n; i++) if (dist1[i] > mx) mx = dist1[i], idx = i;
	memset(dist1, 0, sizeof(dist1));
	dfs(idx, idx, dist1);

	mx = 0, idx = 1;
	for (int i = 1; i <= n; i++) if (dist1[i] > mx) mx = dist1[i], idx = i;
	dfs(idx, idx, dist2);

	for (int i = 1; i <= n; i++) dist1[i] = max(dist1[i], dist2[i]);
	sort(t+1, t+m+1), reverse(t+1, t+m+1);
	sort(dist1+1, dist1+n+1);
	ll ans=0;
	for (int i = 1; i <= m; i++) ans += t[i]*dist1[i];
	cout << ans;
	return 0;
}