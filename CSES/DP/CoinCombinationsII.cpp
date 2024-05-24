#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

int dp[109][1000009], c[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> c[i];
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= x; j++) {
			dp[i][j] = dp[i-1][j];
			if (j >= c[i]) {
				dp[i][j] += dp[i][j-c[i]];
				dp[i][j] %= M;
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= x; j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << "\n";
//	}
	cout << dp[n][x];
	//   1 2 3 4 5 6 7 8 9
	// 2 0 0 0 0 1 0 0 0 0
	// 3 0 0 0 0 0 0 0 1 0
	// 5 0 0 0 0 0 0 1 0 3
	return 0;
}
