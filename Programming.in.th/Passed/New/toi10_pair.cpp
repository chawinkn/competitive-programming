#include <bits/stdc++.h>
using namespace std;

char c[1009];
int dp[1009][1009];

int solve(int l, int r) {
	if (l >= r) return 0;
	if (dp[l][r]) return dp[l][r];
	
	dp[l][r] = solve(l+1, r);
	for (int i = l+1; i <= r; i++) {
		if (c[i] != c[l]) continue;
		dp[l][r] = max(dp[l][r], solve(l+1, i-1)+solve(i+1, r)+1);
	}
	return dp[l][r];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i];
	cout << solve(1, n);
	return 0;
}