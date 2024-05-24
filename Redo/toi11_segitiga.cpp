#include <bits/stdc++.h>
using namespace std;

bool dp[259][259][3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q=20;
	while (q--) {
		int n;
		string s;
		cin >> n >> s;
		memset(dp, false, sizeof(dp));
		for (int i = 1; i <= n; i++) dp[i][i][s[i-1]-'0'] = true;
		for (int sz = 2; sz <= n; sz++) {
			for (int i = 1; i+sz-1 <= n; i++) {
				int j=i+sz-1;
				for (int k = i; k < j; k++) {
					if (dp[i][k][0]) dp[i][j][2] |= dp[k+1][j][0], dp[i][j][1] |= dp[k+1][j][1], dp[i][j][0] |= dp[k+1][j][2];
					if (dp[i][k][1]) dp[i][j][2] |= dp[k+1][j][0], dp[i][j][1] |= dp[k+1][j][1], dp[i][j][1] |= dp[k+1][j][2];
					if (dp[i][k][2]) dp[i][j][1] |= dp[k+1][j][0], dp[i][j][2] |= dp[k+1][j][1], dp[i][j][1] |= dp[k+1][j][2];
				}
			}
		}
		cout << (dp[1][n][0] ? "yes" : "no") << "\n";
	}
	return 0;
}