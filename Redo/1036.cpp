#include <bits/stdc++.h>
using namespace std;

int dp[(1<<8)+9];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < (1<<k); i++) dp[i] = 1e9;
	for (int i = 0; i < n; i++) {
		int w, S=0;
		cin >> w;
		for (int j = k-1; j >= 0; j--) {
			int p;
			cin >> p;
			if (p) S |= (1<<j);
		}
		dp[S] = min(dp[S], w);
	}
	for (int i = 0; i < (1<<k); i++) {
		for (int j = 0; j < (1<<k); j++) {
			dp[i|j] = min(dp[i|j], dp[i]+dp[j]);
		}
	}
	cout << dp[(1<<k)-1];
	return 0;
}