#include <bits/stdc++.h>
using namespace std;

int a[409], dp[409][409], cnt[409][409];

// ก๊อปมา ;-;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, K;
	cin >> t >> K;
	int ans=0;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i], dp[i][i] = cnt[i][i] = 1;
		for (int sz = 2; sz <= n; sz++) {
			for (int i = 1; i+sz-1 <= n; i++) {
				int j=i+sz-1;
				dp[i][j] = dp[i][j-1]+1, cnt[i][j] = 1;
				for (int k = i; k < j; k++) {
					if (a[k] != a[j] || cnt[i][k] >= K) continue;
					if (dp[i][k]+dp[k+1][j-1] < dp[i][j]) dp[i][j] = dp[i][k]+dp[k+1][j-1], cnt[i][j] = cnt[i][k]+1;
					else if (dp[i][k]+dp[k+1][j-1] == dp[i][j]) cnt[i][j] = min(cnt[i][j], cnt[i][k]+1);
				}
			}
		}
		ans = max(ans, dp[1][n]);
	}
	cout << ans;
	return 0;
}