#include <bits/stdc++.h>
using namespace std;

int n, l, r, dp[200000009];

int solve(int n) {
	if (n < l+r) return 0;
	if (dp[n]) return dp[n];
	dp[n] = solve((l*n)/(l+r))+solve((r*n)/(l+r))+1;
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> l >> r;
	cout << solve(n)+1;
	return 0;
}