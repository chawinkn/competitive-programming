#include <bits/stdc++.h>
using namespace std;

// DP

int dp[2][10009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int p, w;
		cin >> p >> w;
		for (int j = 0; j <= m; j++) {
			dp[i%2][j] = dp[(i-1)%2][j];
			if (j >= w) dp[i%2][j] = max(dp[i%2][j], dp[(i-1)%2][j-w]+p);
		}
	}
	cout << dp[n%2][m];
	return 0;
}