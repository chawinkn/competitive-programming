#include <bits/stdc++.h>
using namespace std;

// DP MCM

char c[1009];
int dp[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int sz = 2; sz <= n; sz++) {
		for (int i = 1; i+sz-1 <= n; i++) {
			int j=i+sz-1;
			if (c[i] == c[j]) {
				dp[i][j] = dp[i+1][j-1]+1;
			}
			for (int k = i; k < j; k++) {
				dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]);
			}
		}
	}
	cout << dp[1][n];
	return 0;
}