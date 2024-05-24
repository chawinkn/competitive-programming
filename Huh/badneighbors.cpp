#include <bits/stdc++.h>
using namespace std;

int a[49], dp[49], DP[49];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[1] = a[1]; DP[n] = a[n];
	for (int i = 2; i < n; i++) dp[i] = max(dp[i-1], dp[i-2]+a[i]);
	for (int i = n-1; i > 1; i--) DP[i] = max(DP[i+1], DP[i+2]+a[i]);
	cout << max(dp[n-1], DP[2]);
	return 0;
}