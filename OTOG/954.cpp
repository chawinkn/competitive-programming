#include <bits/stdc++.h>
using namespace std;

// 78/150

#define ll long long

ll dp[2][(1<<16)+9];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < (1<<m); j++) dp[0][j] = dp[1][j] = LLONG_MAX;
	for (int i = 1; i <= n; i++) {
		ll w;
		cin >> w;
		int s=0;
		for (int j = 0; j < (1<<m); j++) dp[i%2][j] = LLONG_MAX;
		for (int j = m-1; j >= 0; j--) {
			int p;
			cin >> p;
			if (p) s |= (1<<j);
		}
		dp[i%2][s] = w;
		for (int j = 0; j < 1<<m; j++) {
			dp[i%2][j] = min(dp[i%2][j], dp[(i-1)%2][j]);
			if (dp[(i-1)%2][j] != LLONG_MAX) dp[i%2][j|s] = min(dp[i%2][j|s], dp[(i-1)%2][j]+w);
		}
	}
	cout << dp[n%2][(1<<m)-1];
	return 0;
}