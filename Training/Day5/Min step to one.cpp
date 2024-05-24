#include <bits/stdc++.h>
using namespace std;

// DP

void solve() {
	int n;
	cin >> n;
	vector<int> dp(n+1);
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i-1];
		if (i%2 == 0) dp[i] = min(dp[i], dp[i/2]);
		if (i%3 == 0) dp[i] = min(dp[i], dp[i/3]);
		dp[i]++;
	}
	cout << dp[n] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}