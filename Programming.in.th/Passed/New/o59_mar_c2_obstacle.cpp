#include <bits/stdc++.h>
using namespace std;

int dp[2][20009], qs[1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, s;
	cin >> n >> s;
	int ans=0;
	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;
		for (int j = 1; j <= h; j++) {
			cin >> qs[j];
			qs[j] += qs[j-1];
		}
		memset(dp[i%2], 0, sizeof(dp[i%2]));
		// for (int j = 0; j <= s-i+1; j++) {
		// 	for (int k = 0; k <= min(h, j); k++) {
		// 		dp[i%2][j] = max(dp[i%2][j], dp[(i-1)%2][j-k]+qs[k]);
		// 	}
		// 	ans = max(ans, dp[i%2][j]);
		// }
		for (int j = 1; j <= s+1; j++) {
			for (int k = 0; k <= h; k++) {
				if (j-k >= i) dp[i%2][j] = max(dp[i%2][j], dp[(i-1)%2][j-k-1]+qs[k]);
			}
			ans = max(ans, dp[i%2][j]);
		}
	}
	cout << ans;
	return 0;
}