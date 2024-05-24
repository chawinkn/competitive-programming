#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll qs[50009], dp[2][50009], mn[50009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, K, m;
	cin >> n >> K >> m;
	for (int i = 1; i <= n; i++) cin >> qs[i], qs[i] += qs[i-1];
	for (int i = 1; i <= K; i++) {
		dp[i%2][0] = mn[0] = 1e18;
		for (int j = 1; j <= n; j++) {
			dp[i%2][j] = dp[i%2][j-1];
			mn[j] = min(mn[j-1], dp[(i-1)%2][max(0, j-2)]-qs[j-1]);
			if (j-m+1 >= 1) dp[i%2][j] = min(dp[i%2][j], qs[j]+mn[j-m+1]);
//			for (int k = 1; k <= j-m+1; k++) {
//				dp[i][j] = min(dp[i][j], dp[i-1][max(0, k-2)]+qs[j]-qs[k-1]);
//			}
//			O(N) too slow
//			qs[j] + { min(dp[i-1][max(0, k-2)]-qs[k-1]) for 1 <= k <= j-m+1 }
		}
	}
	cout << qs[n]-dp[K%2][n];
	return 0;
}