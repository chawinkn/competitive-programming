#include <bits/stdc++.h>
using namespace std;

int qs[100009], dp[2][100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, p;
	cin >> n >> k >> p;
	for (int i = 1; i <= n; i++) cin >> qs[i], qs[i] += qs[i-1];
	for (int i = 1; i <= k; i++) {
		memset(dp[i%2], 0, sizeof(dp[i%2]));
		for (int j = 1; j <= n; j++) {
			dp[i%2][j] = max(dp[i%2][j-1], dp[(i-1)%2][max(0, j-p)]+qs[j]-qs[max(0, j-p)]);
		}
	}
	cout << dp[k%2][n];
	return 0;
}