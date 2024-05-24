#include <bits/stdc++.h>
using namespace std;

int a[509], dp[509][509];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int sz = 1; sz <= n; sz++) {
		for (int i = 1; i+sz-1 <= n; i++) {
			int j=i+sz-1;
			if (sz <= 2) dp[i][j] = 0;
			else dp[i][j] = -1e9;
			for (int k = i+1; k < j; k++) {
				dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]+a[i]+a[j]);
			}
		}
	}
	cout << dp[1][n];
	return 0;
}