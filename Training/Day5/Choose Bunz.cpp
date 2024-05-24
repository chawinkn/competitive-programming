#include <bits/stdc++.h>
using namespace std;

// DP C(n,r)

int dp[3][10009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, r, k;
	cin >> n >> r >> k;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) dp[i%2][j] = 1;
			else dp[i%2][j] = (dp[(i-1)%2][j-1]%k+dp[(i-1)%2][j]%k)%k;
		}
	}
	cout << dp[n%2][r];
	return 0;
}