#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, c[509];
ll dp[509][29][29];

ll solve(int i, int f, int s) {
	if (i > n) return 0;
	if (dp[i][f][s]) return dp[i][f][s];
	
	if (f == c[i] || s == c[i]) return dp[i][f][s] = solve(i+1, f, s);
	
	return dp[i][f][s] = min(solve(i+1, c[i], s), solve(i+1, f, c[i]))+1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> c[i];
		cout << solve(1, 0, 0) << "\n";
//		for (int i = n-1; i >= 1; i--) {
//	        for (int f = 0; f <= 20; f++) {
//	            for (int s = 0; s <= 20; s++) {
//	            	if (f == c[i] || s == c[i]) dp[i][f][s] = dp[i+1][f][s];
//	            	else dp[i][f][s] = min(dp[i+1][c[i]][s], dp[i+1][f][c[i]])+1;
//	            }
//	        }
//	    }
//	    cout << dp[1][0][0] << "\n";
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}