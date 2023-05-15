#include <bits/stdc++.h>
using namespace std;

int dp[1000009], c[1000009];

int main() {
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= x; i++) {
		dp[i] = 1e8;
		for (int j = 1; j <= n; j++) {
			if (i >= c[j]) {
				dp[i] = min(dp[i], dp[i-c[j]]+1);
			}
		}
	}
	if (dp[x] != 1e8) cout << dp[x];
	else cout << -1;
	return 0;
}
