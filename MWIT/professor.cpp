#include <bits/stdc++.h>
using namespace std;

int a[2009];
bool dp[2][1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, sum=0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	if (sum%2 != 0) {
		cout << "No";
		return 0;
	}
	dp[0][0] = true;
	for (int i = 1; i <= n; i++) {
		// memset(dp[i%2], false, sizeof(dp[i%2]));
		for (int j = 0; j <= sum/2; j++) {
			dp[i%2][j] = dp[(i-1)%2][j];
			if (j >= a[i]) dp[i%2][j] |= dp[(i-1)%2][j-a[i]];
		}
		if (dp[i%2][sum/2]) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}