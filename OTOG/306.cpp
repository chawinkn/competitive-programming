#include <bits/stdc++.h>
using namespace std;

int dp[10009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, c;
	cin >> n >> dp[1];
	for (int i = 2; i <= n; i++) {
		cin >> c;
		dp[i] = max(dp[i-1], dp[i-2]+c);
	}
	cout << dp[n];
	return 0;
}
