#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[509][509];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, X, Y;
	cin >> N >> X >> Y;
	for (int i = 0; i <= X; i++) for (int j = 0; j <= Y; j++) dp[i][j] = 1e18;
	dp[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		for (int j = X; j >= 0; j--) {
			for (int k = Y; k >= 0; k--) {
				dp[j][k] = min(dp[j][k], dp[j][k]);
				int jj=min(j+x, X), kk=min(k+y, Y);
				dp[jj][kk] = min(dp[jj][kk], dp[j][k]+c);
			}
		}
	}
	cout << (dp[X][Y] != 1e18 ? dp[X][Y] : -1);
	return 0;
}