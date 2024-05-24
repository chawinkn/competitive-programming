#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll qs[409], dp[409][409];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> qs[i], qs[i] += qs[i-1];
	for (int sz = 2; sz <= n; sz++) {
		for (int i = 1; i+sz-1 <= n; i++) {
			int j=i+sz-1;
			dp[i][j] = 1e18;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+qs[j]-qs[i-1]);
			}
		}
	}
	cout << dp[1][n];
	return 0;
}