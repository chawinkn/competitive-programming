#include <bits/stdc++.h>
using namespace std;

int dp[1000009];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1e6;
		int num=i;
		while (num > 0) {
			dp[i] = min(dp[i], dp[i-num%10]+1);
			num /= 10;
		}
	}
	cout << dp[n];
	return 0;
}
