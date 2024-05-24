#include <bits/stdc++.h>
using namespace std;

int dp[109];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) 
		for (int j = i; j <= n; j++) 
			dp[j] += dp[j-i];
	cout << dp[n];
	return 0;
}