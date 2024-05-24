#include <bits/stdc++.h>
using namespace std;

#define M 10000009

char arr[201][201];
int dp[201][201][1501];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> arr[i][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == '#') continue;
			for (int k = 0; k <= r; k++) {
				if (i == 1 && j == 1) {
					dp[i][j][k] = 1;
					break;
				}
				if (arr[i][j] == 'X') dp[i][j][k] = dp[i-1][j][k-1]+dp[i][j-1][k-1];
				else dp[i][j][k] = dp[i-1][j][k]+dp[i][j-1][k];
				dp[i][j][k] %= M;
			}
		}
	}
	int ans=0;
	for (int i = 0; i <= r; i++) {
		ans += dp[n][m][i];
		ans %= M;
	}
	cout << ans;
	return 0;
}
