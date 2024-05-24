#include <bits/stdc++.h>
using namespace std;

// DFS + DP (Knapsack)

#define ll long long

ll a[5009];
int b[5009], best[5009];
bool visited[5009];

int dfs(int u, vector<pair<int,int>> g[]) {
	if (visited[u]) return best[u];
	visited[u] = true;
	int N=g[u].size();
	vector<vector<int>> dp(2, vector<int>(b[u]));
	for (int i = 1; i <= N; i++) {
		int w=g[u][i-1].first, v=g[u][i-1].second;
		for (int j = 0; j < b[u]; j++) {
			dp[i%2][j] = dp[(i-1)%2][j];
			if (j >= w) dp[i%2][j] = max(dp[i%2][j], dp[(i-1)%2][j-w]+dfs(v, g));
		}
	}
	return best[u] = dp[N%2][b[u]-1]+1;
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	vector<pair<int,int>> g[n+1];
	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back({b[v], v});
		g[v].push_back({b[u], u});
	}
	for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end(), greater<pair<int,int>>());
	memset(best, 0, sizeof(best));
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++) dfs(i, g);
	ll ans=0;
	for (int i = 1; i <= n; i++) ans += a[i]*best[i];
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}