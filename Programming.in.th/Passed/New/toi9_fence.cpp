#include <bits/stdc++.h>
using namespace std;

void solve() {
	int m, n, t, r, c, dp[509][509]={0};
		
	cin >> m >> n >> t;
	while (t--) {
		cin >> r >> c;
		dp[r+1][c+1] = 1;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) dp[i][j] += dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
	}
	
	for (int k = min(m, n); k >= 1; k--) {
		for (int i = k; i <= m; i++) {
			for (int j = k; j <= n; j++) {
				int out=dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k];
				int in=dp[i-1][j-1]-dp[i-1][j-k+1]-dp[i-k+1][j-1]+dp[i-k+1][j-k+1];
				if (out-in != 0) continue;
				cout << k << "\n";
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q=2;
	while (q--) solve();
	return 0;
}
