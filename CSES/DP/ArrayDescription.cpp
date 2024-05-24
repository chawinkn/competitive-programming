#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007

ll dp[100009][109], x[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> x[i];
	if (x[1] == 0) {
		for (int i = 1; i <= m; i++) dp[1][i] = 1;
	} 
	else dp[0][x[1]] = 1;
	for (int i = 1; i <= n; i++) {
		if (x[i] == 0) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] += dp[i-1][j];
				if (j > 1) dp[i][j] += dp[i-1][j-1];
				if (j <= m-1) dp[i][j] += dp[i-1][j+1];
				dp[i][j] %= M;
			}
		}
		else {
			dp[i][x[i]] += dp[i-1][x[i]];
			if (x[i] > 1) dp[i][x[i]] += dp[i-1][x[i]-1];
			if (x[i] <= m-1)dp[i][x[i]] += dp[i-1][x[i]+1];
			dp[i][x[i]] %= M;
		}
	}
	ll ans=0;
	for (int i = 1; i <= m; i++) {
		ans += dp[n][i];
		ans %= M;	
	}
	cout << ans;
	return 0;
}
