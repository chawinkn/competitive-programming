#include <bits/stdc++.h>
using namespace std;

int c[509], dp[509][509];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i], dp[i][i] = 1;
	for (int sz = 2; sz <= n; sz++) {
		for (int i = 1; i+sz-1 <= n; i++) {
			int j=i+sz-1;
			dp[i][j] = 1e9;
			if (c[i] == c[j]) {
				if (sz == 2) dp[i][j] = 1;
				else dp[i][j] = dp[i+1][j-1];
			}
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
			}
		}
	}
	cout << dp[1][n];
	return 0;
}