#include <bits/stdc++.h>
using namespace std;

int dp[1000069];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int ans=1e9;
	for (int i = 1; i <= n+15; i++) {
		dp[i] = 1e9;
		if (i >= 1) dp[i] = min(dp[i], dp[i-1]+500);
		if (i >= 2) dp[i] = min(dp[i], dp[i-2]+800);
		if (i >= 5) dp[i] = min(dp[i], dp[i-5]+1500);
		if (i >= 15) dp[i] = min(dp[i], dp[i-15]+3000);
		if (i >= n) ans = min(ans, dp[i]);
	}
	cout << ans;
	return 0;
}