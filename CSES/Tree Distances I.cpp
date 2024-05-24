#include <bits/stdc++.h>
using namespace std;

vector<int> g[200009];
int dist1[200009], dist2[200009];

void dfs(int u, int p, int dist[]) {
	for (auto v : g[u]) {
		if (v == p) continue;
		dist[v] = dist[u]+1;
		dfs(v, u, dist);
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
	dfs(1, 1, dist1);
	int mx=0, u=1;
	for (int i = 1; i <= n; i++) {
		if (dist1[i] > mx) {
			mx = dist1[i];
			u = i;
		}
	}
	memset(dist1, 0, sizeof(dist1));
	dfs(u, u, dist1);
	mx = 0;
	for (int i = 1; i <= n; i++) {
		if (dist1[i] > mx) {
			mx = dist1[i];
			u = i;
		}
	}
	dfs(u, u, dist2);
	for (int i = 1; i <= n; i++) cout << max(dist1[i], dist2[i]) << " ";
	return 0;
}