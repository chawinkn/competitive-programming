#include <bits/stdc++.h>
using namespace std;

const int M = 1e6+3;
int C[9], dp[2][100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	C[1] = 1, C[2] = 5, C[3] = 10, C[4] = 25, C[5] = 50;
	dp[0][0] = 1;
	for (int i = 1; i <= 5; i++) {
		memset(dp[i%2], 0, sizeof(dp[i%2]));
		for (int j = 0; j <= 100000; j++) {
			dp[i%2][j] += dp[(i-1)%2][j], dp[i%2][j] %= M;
			if (j >= C[i]) dp[i%2][j] += dp[i%2][j-C[i]], dp[i%2][j] %= M;
		}
	}
	while (q--) {
		int k;
		cin >> k;
		cout << dp[5%2][k] << "\n";
	}
	return 0;
}