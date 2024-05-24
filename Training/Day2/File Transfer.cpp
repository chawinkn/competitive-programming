#include <bits/stdc++.h>
using namespace std;

// BFS, DFS

vector<int> g[1009];
bool visited[1009][1009];

void dfs(int p, int u) {
	if (visited[p][u]) return;
	visited[p][u] = true;
	for (auto v : g[u]) dfs(p, v);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	while (m--) {
		int s, e;
		cin >> s >> e;
		g[s].push_back(e);
	}
	for (int i = 1; i <= n; i++) dfs(i, i);
	while (q--) {
		int t, u;
		cin >> t >> u;
		cout << (visited[t][u] ? "Yes" : "No") << "\n";
	}
	return 0;
}