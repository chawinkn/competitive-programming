#include <bits/stdc++.h>
using namespace std;

vector<int> g[200009];
int dist[200009];

void dfs(int u, int p) {
	for (auto v : g[u]) {
		if (v == p) continue;
		dist[v] = dist[u]+1;
		dfs(v, u);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n-1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);
	int mx=0, u=1;
	for (int i = 1; i <= n; i++) {
		if (dist[i] > mx) {
			mx = dist[i];
			u = i;
		}
	}
	memset(dist, 0, sizeof(dist));
	dfs(u, u);
	int ans=0;
	for (int i = 1; i <= n; i++) ans = max(ans, dist[i]);
	cout << ans;
	return 0;
}