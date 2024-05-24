#include <bits/stdc++.h>
using namespace std;

int arr[53][53];
long long int dp[53][53];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n, o, x, y;
	cin >> m >> n >> o;
	for (int i = 0; i < o; i++) {
		cin >> x >> y;
		arr[y][x] = 1;
	}
	dp[1][1] = 1;
//	for (int i = 2; i <= n; i++) if (!arr[i][1]) dp[i][1] = dp[i-1][1];
//	for (int i = 2; i <= m; i++) if (!arr[1][i]) dp[1][i] = dp[1][i-1];
//	for (int i = 2; i <= n; i++) {
//		for (int j = 2; j <= m; j++) if (!arr[i][j]) dp[i][j] = dp[i-1][j]+dp[i][j-1];
//	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!arr[i][j]) dp[i][j] += dp[i-1][j]+dp[i][j-1];
		}
	}
	cout << dp[n][m];
	return 0;
}
