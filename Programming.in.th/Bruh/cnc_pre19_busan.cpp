#include <bits/stdc++.h>
using namespace std;

int l[2009], r[2009], dp[3009][3009][2];

// Only s = 0
// 34/100

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, s;
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) cin >> l[i];
	for (int i = 1; i <= n; i++) cin >> r[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (l[i] >= 0 && r[i] < 0) {
				dp[i][j][0] = max(dp[i-1][j][0], j+r[i] >= 0 ? dp[i-1][j+r[i]][0]+l[i] : 0);
				dp[i][j][1] = dp[i-1][j][1];
			}
			else if (l[i] < 0 && r[i] >= 0) {
				dp[i][j][0] = dp[i-1][j][0];
				dp[i][j][1] = max(dp[i-1][j][1], j+l[i] >= 0 ? dp[i-1][j+l[i]][1]+r[i] : 0);
			}
			else if (l[i] >= 0 && r[i] >= 0) {
				dp[i][j][0] = dp[i-1][j][0]+l[i];
				dp[i][j][1] = dp[i-1][j][1]+r[i];
			}
			else if (l[i] < 0 && r[i] < 0) {
				dp[i][j][0] = dp[i-1][j][0];
				dp[i][j][1] = dp[i-1][j][1];
			}
		}
	}
	cout << dp[n][m][0]+dp[n][m][1];
	return 0;
}