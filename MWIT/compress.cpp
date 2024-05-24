#include <bits/stdc++.h>
using namespace std;

int dp[509][509];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, r;
	cin >> n >> m >> r;
	int k=2*r+1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> dp[i][j];
			dp[i][j] += dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		}
	}
	for (int i = k; i <= n; i++) {
		for (int j = k; j <= m; j++) {
			cout << dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k] << " ";
		}
		cout << "\n";
	}
	return 0;
}

