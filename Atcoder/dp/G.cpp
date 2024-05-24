#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1e5+9;
vector<int> g[MAX_N], dp(MAX_N);
bool visited[MAX_N];

int dfs(int u) {
	if (dp[u]) return dp[u];
	for (auto i : g[u]) {
		dp[i] = dfs(i);
		dp[u] = max(dp[u], dp[i]+1);
	}
	return dp[u];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, u, v;
	cin >> n >> m;
	while (m--){
		cin >> u >> v;
		g[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) dfs(i);
	int ans=0;
	for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans;
	return 0;
}
