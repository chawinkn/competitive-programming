#include <bits/stdc++.h>
using namespace std;

vector<int> dp(1000009, 1e6);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, p;
	cin >> n;
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> p;
		dp[i+1] = min(dp[i+1], dp[i]+1);
		if (i+p <= n) dp[i+p] = min(dp[i+p], dp[i]+1);
	}
	cout << dp[n];
	return 0;
}
