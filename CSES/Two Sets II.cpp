#include <bits/stdc++.h>
using namespace std;

const int M=1e9+7;
int dp[509][150009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	if (n*(n+1)/2 % 2 != 0) {
		cout << 0;
		return 0;
	}
	int sum=(n*(n+1))/4;
	dp[0][0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= sum; j++) {
			dp[i][j] = dp[i-1][j];
			if (j < i) continue;
			dp[i][j] += dp[i-1][j-i]%M;
			dp[i][j] %= M;
		}
	}
	cout << dp[n-1][sum];
	return 0;
}