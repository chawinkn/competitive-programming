#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[59][59];
bool doggo[59][59];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, n, o, x, y;
	cin >> m >> n >> o;
	while (o--) {
		cin >> x >> y;
		doggo[y][x] = true;
	}
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (doggo[i][j]) continue;
			dp[i][j] += dp[i-1][j]+dp[i][j-1];
		}
	}
	cout << dp[n][m];
	return 0;
}
