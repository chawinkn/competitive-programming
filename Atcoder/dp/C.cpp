#include <bits/stdc++.h>
using namespace std;

int dp[100009][4], a[100009], b[100009], c[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i <= n; i++) {
		dp[i][1] = max(dp[i-1][2], dp[i-1][3]) + a[i];
		dp[i][2] = max(dp[i-1][1], dp[i-1][3]) + b[i];
		dp[i][3] = max(dp[i-1][1], dp[i-1][2]) + c[i];
	}
	cout << max({dp[n][1], dp[n][2], dp[n][3]});
	return 0;
}
