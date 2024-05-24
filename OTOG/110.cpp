#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[2][419];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, sum=0;
	cin >> n;
	sum = (n*(n+1))/2;
	if (sum%2 != 0) {
		cout << 0;
		return 0;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum/2; j++) {
			dp[i%2][j] = dp[(i-1)%2][j];
			if (j >= i) dp[i%2][j] += dp[(i-1)%2][j-i];
		}
	}
	cout << dp[n%2][sum/2]/2;
	return 0;
}