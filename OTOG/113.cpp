#include <bits/stdc++.h>
using namespace std;

int dp[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, c;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		if (i <= 2) continue;
		else dp[i] = max(dp[i-1], dp[i-3]+c);
	}
	cout << dp[n];
	return 0;
}
