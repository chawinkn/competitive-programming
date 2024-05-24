#include <bits/stdc++.h>
using namespace std;

int n, dp[109][109], x[109];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	n *= 2;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int sz = 1; sz <= n; sz++) {
		for (int i = 1; i <= n-sz+1; i++) {
			int j=i+sz-1;
			dp[i][j] = max(x[i]+max(dp[i+2][j], dp[i+1][j-1]), x[j]+max(dp[i+1][j-1], dp[i][j-2]));
		}
	}
	cout << dp[1][n];
	return 0;
}