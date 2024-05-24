#include <bits/stdc++.h>
using namespace std;

int dp[300009];
vector<int> g[300009];

//void dfs(int u) {
//	for (auto i : g[u]) {
//		if (dp[u]+1 > dp[i] && i > u) {
//			dp[i] = dp[u]+1;
//			dfs(i);
//		}
//	}
//}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, u, v, ans=0;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		g[min(u, v)].push_back(max(u, v));
	}
	for (int i = 1; i <= n; i++) {
		for (auto j : g[i]) {
			dp[j] = max(dp[j], dp[i]+1);
		}
	}
	for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans+1;
	return 0;
}
