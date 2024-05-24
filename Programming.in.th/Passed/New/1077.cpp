#include <bits/stdc++.h>
using namespace std;

int dp[1007][1007];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, x, y, k;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		x++; y++;
		dp[y][x]++;
	}
	for (int i = 1; i <= 1001; i++) {
		for (int j = 1; j <= 1001; j++) {
			dp[i][j] += dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> k;
		x++; y++;
		int y1=max(y-k-1, 0), x1=max(x-k-1, 0), y2=min(y+k, 1001), x2=min(x+k, 1001); 
		cout << dp[y2][x2]-dp[y2][x1]-dp[y1][x2]+dp[y1][x1] << "\n";
	}
	return 0;
}
