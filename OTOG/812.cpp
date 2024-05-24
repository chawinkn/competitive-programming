#include <bits/stdc++.h>
using namespace std;

// 80/100

int dp[2][(1<<20)+9], p[29];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) cin >> p[j];
		for (int j = 0; j < 1<<n; j++) {
			dp[i%2][j] = 1e9;
			for (int k = 0; k < n; k++) {
				if (!(j&1<<k)) continue;
				dp[i%2][j] = min(dp[i%2][j], dp[(i-1)%2][j^(1<<k)]+p[k]);
			}
		}
	} 
	cout << dp[n%2][(1<<n)-1];
	return 0;
}