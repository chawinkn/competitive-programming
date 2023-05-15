#include <bits/stdc++.h>
using namespace std;

int dp[1009][100009], h[1009], s[1009];

int main() {
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= x; j++) {
			dp[i][j] = dp[i-1][j];
			if (j >= h[i]) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-h[i]]+s[i]);
			}
		}
	}
	cout << dp[n][x];
	return 0;
}
