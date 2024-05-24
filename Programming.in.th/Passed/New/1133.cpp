#include <bits/stdc++.h>
using namespace std;

vector<int> station[1000009];
vector<vector<int>> dp(509, vector<int>(509, 1e9)); // Minimum change to change from line i to j

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, a, b, q;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a;
		for (int j = 1; j <= a; j++) {
			cin >> b;
			station[b].push_back(i);
		}
	}
	for (int k = 1; k <= n; k++) {
		for (auto i : station[k]) {
			for (auto j : station[k]) {
				if (i == j) dp[i][j] = 0;
				else dp[i][j] = 1;
			}
		}
	}
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
			}
		}
	}
	cin >> q;
	while (q--) {
		cin >> a >> b;
		int ans=1e9;
		// Check all posible to change from line a to b
		for (auto i : station[a]) {
			for (auto j : station[b]) {
				ans = min(ans, dp[i][j]);
			}
		}
		if (ans == 1e9) cout << "impossible\n";
		else cout << ans << "\n";
	}
	return 0;
}
