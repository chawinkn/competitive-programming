#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[40009];
int yy=409, xx=409, ans[409][409];

void dfs(int u, int p, int y, int x) {
	ans[y][x] = u;
	yy = min(yy, y), xx = min(xx, x);
	for (auto [v,d] : g[u]) {
		if (v == p) continue;
		if (d == 1) dfs(v, u, y, x-1);
		else if (d == 2) dfs(v, u, y-1, x);
		else if (d == 3) dfs(v, u, y, x+1);
		else dfs(v, u, y+1, x);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m*n-1; i++) {
		int u, v; char t;
		cin >> u >> t >> v;
		if (t == 'U') {
			g[u].push_back({v, 4});
			g[v].push_back({u, 2});
		}
		else {
			g[u].push_back({v, 3});
			g[v].push_back({u, 1});
		}
	}
	dfs(0, 0, n, n);
	for (int i = yy; i < yy+m; i++) {
		for (int j = xx; j < xx+n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}