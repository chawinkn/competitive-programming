#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

int dp[1000009];

int main() {
	int n;
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i >= j) {
				dp[i] += dp[i-j]%M;
				dp[i] %= M;
			}
		}
	}
	cout << dp[n];
	return 0;
}
