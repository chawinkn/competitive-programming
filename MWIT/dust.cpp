#include <bits/stdc++.h>
using namespace std;

// 56/100

int b[200009], dp[2][200009], mx[200009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, K;
	cin >> n >> K;
	for (int i = 1; i <= n; i++) cin >> b[i];
	int ans=0;
	for (int i = 1; i <= K; i++) {
		mx[0] = 0;
		for (int j = 1; j <= n; j++) {
			mx[j] = max(mx[j-1], dp[(i-1)%2][j]+j);
			if (i == 1) dp[i%2][j] = b[j]-1;
			else {
				dp[i%2][j] = max(dp[i%2][j-1]-1, mx[j-1]+b[j]-j);
				// dp[i][j] = max dp[i-1][k]+b[j]-j+k  1 <= k < j
				//            max     dp[i-1][k]+k

				// for (int k = 1; k < j; k++) {
				// 	dp[i%2][j] = max(dp[i%2][j], dp[(i-1)%2][k]+b[j]-(j-k));
				// }
			}
			if (i == K) ans = max(ans, dp[i%2][j]);
		}
	}
	cout << ans;
	return 0;
}