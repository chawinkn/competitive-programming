#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, ans=0, dp[59]={0};
		char c;
		cin >> n >> c;
		for (int i = 2; i <= n; i++) {
			cin >> c;
			if (c == '*') {
				dp[i] = -1e9;
				continue;
			}
			dp[i] = max(dp[i-1], dp[i-2])+(c == '@');
			ans = max(ans, dp[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}