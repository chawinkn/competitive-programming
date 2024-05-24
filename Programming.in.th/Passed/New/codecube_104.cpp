#include <bits/stdc++.h>
using namespace std;

int dp[1009][3009], arr[1009];
// min change for first i element ending with j

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);;
	int n, t;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i][0] = 1e9;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3000; j++) dp[i][j] = min(dp[i][j-1], dp[i-1][j-1]+(arr[i]!=j));
	}
	int ans=1e9;
	for (int i = 1; i <= 3000; i++) ans = min(ans, dp[n][i]);
	cout << ans;
	return 0;
}
