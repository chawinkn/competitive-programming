#include <bits/stdc++.h>
using namespace std;

int dp[100007], sum[100007];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	sum[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = sum[i-1];
		if (i-k-1 >= 0) dp[i] -= sum[i-k-1];
		dp[i] %= 2009;
		sum[i] += sum[i-1]+dp[i];
	}
	cout << dp[n];
	return 0;
}