#include <bits/stdc++.h>
using namespace std;

int dp[19];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, ans=1e9;
	cin >> n;
	for (int i = 1; i <= n+15; i++) {
		int mn=1e9;
		if (i >= 1) mn = min(mn, dp[(i-1)%15]+500); 
		if (i >= 2) mn = min(mn, dp[(i-2)%15]+800);
		if (i >= 5) mn = min(mn, dp[(i-5)%15]+1500);
		if (i >= 15) mn = min(mn, dp[(i-15)%15]+3000);
		dp[i%15] = mn;
		if (i >= n) ans = min(ans, dp[i%15]);
	}
	cout << ans;
	return 0;
}