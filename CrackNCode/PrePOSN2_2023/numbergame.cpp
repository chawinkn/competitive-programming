#include <bits/stdc++.h>
using namespace std;

int a[509], dp[509][509];
bool memo[509][509]; 
 
int solve(int l, int r) {
	if (l == r-1) return 0;
	if (memo[l][r]) return dp[l][r];
	
	dp[l][r] = -1e9;
	memo[l][r] = true;
	for (int i = l+1; i < r; i++) {
		dp[l][r] = max(dp[l][r], solve(l, i)+solve(i, r)+a[l]+a[r]);
	}
	
	return dp[l][r];
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << solve(1, n);
	return 0;
}