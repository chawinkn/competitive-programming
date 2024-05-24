#include <bits/stdc++.h>
using namespace std;

long long dp[109][100009], w[109], v[109];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	
	// dp[i][j] = maximum sum items 1-i weight <= j
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i-1][j];
			if (j < w[i]) continue;
			dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
		}
	}
	cout << dp[n][m];
	return 0;
}
