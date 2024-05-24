#include <bits/stdc++.h>
using namespace std;

const int M=1e6+7;
int dp[2][50009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, v;
	cin >> n >> m;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> v;
		for (int j = 0; j <= m; j++) {
			dp[i%2][j] = dp[(i-1)%2][j];
			if (j >= v) dp[i%2][j] += dp[(i-1)%2][j-v];
			dp[i%2][j] %= M;
		}
	}
	cout << dp[n%2][m];
	return 0;
}