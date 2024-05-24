#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int x[1009][1009];
pair<int,int> dp[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) cin >> x[i][j];
	}
	for (int j = 1; j <= n; j++) dp[1][j] = {x[1][j], 1};
	for (int i = 2; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int mx=0;
			if (i%2) {
				mx = max(dp[i-1][j-1].f, dp[i-1][j].f);	
				if (mx == dp[i-1][j-1].f) dp[i][j].s += dp[i-1][j-1].s;
				if (mx == dp[i-1][j].f) dp[i][j].s += dp[i-1][j].s;
			}
			else {
				mx = max(dp[i-1][j].f, dp[i-1][j+1].f);	
				if (mx == dp[i-1][j].f) dp[i][j].s += dp[i-1][j].s;
				if (mx == dp[i-1][j+1].f) dp[i][j].s += dp[i-1][j+1].s;
			}
			dp[i][j].f = mx+x[i][j];
 		}
	}
	int ans=0, cnt=0;
	for (int i = 1; i <= n; i++) ans = max(ans, dp[m][i].f);
	for (int i = 1; i <= n; i++) if (ans == dp[m][i].f) cnt += dp[m][i].s;
	cout << ans << " " << cnt;
	return 0;
}