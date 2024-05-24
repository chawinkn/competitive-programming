#include <bits/stdc++.h>
using namespace std;

// DP

int C[19], dp[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> C[i];
	for (int i = 1; i <= m; i++) {
		dp[i] = 1e9;
		for (int j = 1; j <= n; j++) {
			if (i >= C[j]) dp[i] = min(dp[i], dp[i-C[j]]+1);
		}
	}
	cout << (dp[m] != 1e9 ? dp[m] : 0);
	return 0;
}