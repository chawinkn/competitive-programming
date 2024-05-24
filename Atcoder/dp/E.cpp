#include <bits/stdc++.h>
using namespace std;

long long dp[109][100009], w[109], v[109];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, mx=0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
		mx += v[i];
	}
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= mx; j++) dp[i][j] = 1e12+9;
	}
	dp[0][0]=0;
	
	// dp[i][j] = minimum weight items 1-i sum j
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= mx; j++) {
			dp[i][j] = dp[i-1][j];
			if (j < v[i]) continue;
			dp[i][j] = min(dp[i][j], dp[i-1][j-v[i]]+w[i]);
		}
	}
	for (int i = mx; i >= 0; i--) {
		if (dp[n][i] <= m) {
			cout << i;
			break;
		}
	}
	return 0;
}
