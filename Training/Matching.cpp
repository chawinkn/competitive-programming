#include <bits/stdc++.h>
using namespace std;

const int M=1e9+7;

int dp[2][(1<<21)+9];
bool a[29][29];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> a[i][j];
	}
	for (int i = 0; i < n; i++) dp[0][1<<i] = a[0][i];
	for (int i = 1; i < n; i++) {
		memset(dp[i%2], 0, sizeof(dp[i%2]));
		for (int j = 0; j < 1<<n; j++) {
			if (__builtin_popcount(j) != i+1) continue;
			for (int k = 0; k < n; k++) {
				if (j&(1<<k) && a[i][k]) {
					dp[i%2][j] += dp[(i-1)%2][j^(1<<k)];
					dp[i%2][j] %= M;
				}
			}
		}
	}
	cout << dp[(n-1)%2][(1<<n)-1];
	return 0;
}