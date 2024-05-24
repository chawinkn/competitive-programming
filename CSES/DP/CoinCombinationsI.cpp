#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

int dp[1000009], c[1000009];

int main() {
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> c[i];
	dp[0] = 1;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= n; j++) {
			if (i >= c[j]) {
				dp[i] += dp[i-c[j]]%M;
				dp[i] %= M;
			}
		}
	}
	cout << dp[x];
	return 0;
}
