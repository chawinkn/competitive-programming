#include <bits/stdc++.h>
using namespace std;

int h[100009], dp[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> h[i];
	dp[2] = abs(h[2]-h[1]);
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i-1]+abs(h[i]-h[i-1]);
		for (int j = 2; j <= k; j++) {
			if (i <= j) continue;
			dp[i] = min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
		}
	}
	cout << dp[n];
	return 0;
}
