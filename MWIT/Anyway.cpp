#include <bits/stdc++.h>
using namespace std;

const int M = 1e6;

int dp[1009][1009];
bool die[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int x, y, k, a, b;
	cin >> x >> y >> k;
	while (k--) {
		cin >> a >> b;
		die[b][a] = true;
	}
	dp[0][0] = 1;
	for (int i = 0; i <= y; i++) {
		for (int j = 0; j <= x; j++) {
			if (die[i][j]) continue;
			if (i >= 1) dp[i][j] += dp[i-1][j];
			if (j >= 1) dp[i][j] += dp[i][j-1];
			dp[i][j] %= M;
		}
	}
	cout << dp[y][x];
	return 0;
}
