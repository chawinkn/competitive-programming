#include <bits/stdc++.h>
using namespace std;

const int M=2e3+9;

int qs[100009], dp[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	dp[0] = qs[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = qs[i-1];
		if (i-k-1 >= 0) dp[i] -= qs[i-k-1];
		dp[i] %= M;
		qs[i] = qs[i-1]+dp[i];
	}
	cout << dp[n];
	return 0;
}