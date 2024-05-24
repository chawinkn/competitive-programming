#include <bits/stdc++.h>
using namespace std;

// WTF???????

int a[409];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q, K;
	cin >> q >> K;
	int ans=0;
	while (q--) {
		int n;
		cin >> n;
		vector<vector<int>> dp(n+1, vector<int>(n+1, 1e9));
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			dp[i][i] = 1;	
		}
		for (int sz = 2; sz <= n; sz++) {
			for (int i = 1; i+sz-1 <= n; i++) {
				int j=i+sz-1;
				for (int k = i; k < j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
				}
				if (a[i] == a[j]) dp[i][j]--;
			}
		}
		ans = max(ans, dp[1][n]);
	}
	cout << ans;
	return 0;
}