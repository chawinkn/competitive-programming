#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[2][509][509];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x, y, xi, yi, c;
	cin >> n >> x >> y;
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			dp[0][i][j] = 1e18;
		}
	}
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> xi >> yi >> c;
		for (int j = 0; j <= x; j++) {
			for (int k = 0; k <= y; k++) {	
				// Not pick
				dp[i%2][j][k] = dp[(i-1)%2][j][k];
			}
		}
		for (int j = 0; j <= x; j++) {
			for (int k = 0; k <= y; k++) {
				// Pick
				dp[i%2][min(x,j+xi)][min(y,k+yi)] = min(
					dp[i%2][min(x,j+xi)][min(y,k+yi)], 
					dp[(i-1)%2][j][k]+c
				);
			}
		}
	}
	cout << (dp[n%2][x][y] != 1e18 ? dp[n%2][x][y] : -1);
	return 0;
}