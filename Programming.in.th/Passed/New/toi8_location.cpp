#include <bits/stdc++.h>
using namespace std;

int dp[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, n, k, ans=0;
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> dp[i][j];
			dp[i][j] += dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		}
	}
	for (int i = k; i <= m; i++) {
		for (int j = k; j <= n; j++) {
			ans = max(ans, dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k]);
		}
	}
	cout << ans;
	return 0;
}
