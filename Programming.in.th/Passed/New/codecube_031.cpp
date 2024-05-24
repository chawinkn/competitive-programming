#include <bits/stdc++.h>
using namespace std;

#define M 909091

long long dp[10009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] += (dp[j-1]*dp[i-j])%M;
			dp[i] %= M;
		}
	}
	cout << dp[n];
	return 0;
}
