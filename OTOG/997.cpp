#include <bits/stdc++.h>
using namespace std;

#define ll long long

int p[100009];
vector<pair<int,int>> g[100009];
bool visited[100009], a[100009][69];

int find(int u) {
	if (u == p[u]) return u;
	return p[u]=find(p[u]);
}

void dfs(int u) {
	if (visited[u]) return;
	visited[u] = true;
	for (auto [v,w] : g[u]) {
		dfs(v);
		a[find(u)][w] = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	iota(p+1, p+n+1, 1);
	while (m--) {
		int u, v, a;
		cin >> u >> v >> a;
		g[u].push_back({v, a});
		g[v].push_back({u, a});
		u = find(u), v = find(v);
		if (u == v) continue;
		p[u] = v;
	}
	for (int i = 1; i <= n; i++) dfs(i);
	while (q--) {
		int s, t;
		cin >> s >> t;
		s = find(s), t = find(t);
		if (p[s] != p[t]) cout << -1;
		else {
			ll ans=0;
			for (int i = 0; i <= 60; i++) {
				if (a[s][i]) ans += 1ll<<i;
			}
			cout << ans;
		}
		cout << "\n";
	}
	return 0;
}