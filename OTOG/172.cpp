#include <bits/stdc++.h>
using namespace std;

int arr[19][19], dp[19][19];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> arr[i][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + arr[i][j];
		}
	}
	cout << dp[n][m];
	return 0;
}
