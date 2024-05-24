#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(19, vector<int>(19, 1e9));
int a[19][19];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, s, ans=1e9, y, x;
	vector<int> path;
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	}
	dp[s][1] = a[s][1];
	for (int j = 2; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i+1][j-1]})+a[i][j];
			if (j == m && dp[i][j] < ans) ans = dp[i][j], y = i, x = j;
		}
	}
	cout << ans << "\n";
	path.push_back(a[y][x]);
	while (x > 1) {
		if (dp[y][x] == dp[y-1][x-1]+a[y][x]) path.push_back(a[y-1][x-1]), y--, x--;
		else if (dp[y][x] == dp[y][x-1]+a[y][x]) path.push_back(a[y][x-1]), x--;
		else if (dp[y][x] == dp[y+1][x-1]+a[y][x]) path.push_back(a[y+1][x-1]), y++, x--;
	}
	reverse(path.begin(), path.end());
	for (auto i : path) cout << i << " ";
	return 0;
}