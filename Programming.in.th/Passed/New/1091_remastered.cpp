#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3e5+9;
vector<int> g[MAX_N], dp(MAX_N);

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
	int n, u, v, ans=0;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		g[min(u, v)].push_back(max(u, v));
	}
	for (int i = 1; i <= n; i++) ans = max(ans, dfs(i));
	cout << ans+1;
	return 0;
}
