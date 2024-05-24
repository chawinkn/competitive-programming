#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int arr[1009][1009];
pair<int,int> dp[1009][1009]; // (Sum, Number of ways)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) cin >> arr[i][j];
	}
	for (int i = 1; i <= n; i++) dp[1][i] = {arr[1][i], 1};
	for (int i = 2; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int mx=0, cnt=0;
			if (i%2) {
				mx = max(dp[i-1][j-1].f, dp[i-1][j].f);
				if (dp[i-1][j-1].f == mx) cnt += dp[i-1][j-1].s;
				if (dp[i-1][j].f == mx) cnt += dp[i-1][j].s;
			}
			else {
				mx = max(dp[i-1][j].f, dp[i-1][j+1].f);
				if (dp[i-1][j].f == mx) cnt += dp[i-1][j].s;
				if (dp[i-1][j+1].f == mx) cnt += dp[i-1][j+1].s;
			}
			dp[i][j] = {mx+arr[i][j], cnt};
		}
	}
	int ans=0, cnt=0;
	for (int i = 1; i <= n; i++) ans = max(ans, dp[m][i].f);
	for (int i = 1; i <= n; i++) {
		if (dp[m][i].f == ans) cnt += dp[m][i].s;
	}
	cout << ans << " " << cnt;
	return 0;
}
