#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

int dp[1009][1009];
char arr[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int h, w;
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) cin >> arr[i][j];
	}
	
	dp[1][1] = 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (arr[i][j] == '#') continue;
			dp[i][j] += dp[i][j-1] + dp[i-1][j];
			dp[i][j] %= M;
		}
	}
	cout << dp[h][w];
	return 0;
}
