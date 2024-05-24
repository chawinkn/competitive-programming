#include <bits/stdc++.h>
using namespace std;

int dp[300009];
vector<int> g[300009];

int dfs(int u) {
	if (dp[u]) return dp[u];
	for (auto v : g[u]) {
		dp[v] = dfs(v);
		dp[u] = max(dp[u], dp[v]+1);
	}
	return dp[u];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		g[min(u,v)].push_back(max(u,v));
	}
	int ans=0;
	for (int i = 1; i <= n; i++) ans = max(ans, dfs(i));
	cout << ans+1;
	return 0;
}