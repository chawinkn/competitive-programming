#include <bits/stdc++.h>
using namespace std;

bool dp[2][100009];

void solve() {
	int n, k;
	cin >> n >> k;
	memset(dp, false, sizeof(dp));
	dp[0][0] = true;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		memset(dp[i%2], false, sizeof(dp[i%2]));
		for (int j = 0; j < k; j++) {
			dp[i%2][j] |= dp[(i-1)%2][j];
			dp[i%2][(j+a)%k] |= dp[(i-1)%2][j];
		}
	}
	int ans=0;
	for (int j = k-1; j >= 0; j--) {
		if (dp[n%2][j]) {
			ans = j;
			break;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}	
	return 0;
}