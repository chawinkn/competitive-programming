#include <bits/stdc++.h>
using namespace std;

// DP Maximum Square With 1

char s[1009][1009];
int dp[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> s[i]+1;
	int ans=0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == '#') continue;
			dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}