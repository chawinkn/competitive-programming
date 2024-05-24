#include <bits/stdc++.h>
using namespace std;

#define ll long long

int ordered[100009][109];
vector<vector<ll>> dp(2, vector<ll>(109, -1e18));

// Top down
// dp[i][j] i = pos j = time
// ll solve(int i, int j) {
// 	if (i < 1 || i > n || j > mxt) return 0;
// 	if (visited[i][j]) return dp[i][j];
// 	visited[i][j] = true;
// 	dp[i][j] = max({dp[i][j], solve(i-1, j+1), solve(i, j+1), solve(i+1, j+1)})+ordered[i][j];
// 	return dp[i][j];
// }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, s, mxt=0;
	cin >> n >> m >> s;
	while (m--) {
		int t, a, b;
		cin >> t >> a >> b;
		mxt = max(mxt, t);
		ordered[t][a] = b;
	}
	dp[0][s] = 0;
	ll ans=0;
	for (int i = 1; i <= mxt; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i%2][j] = max({dp[(i-1)%2][j-1], dp[(i-1)%2][j], dp[(i-1)%2][j+1]})+ordered[i][j];
			ans = max(ans, dp[i%2][j]);
		}
	}
	cout << ans;
	return 0;
}