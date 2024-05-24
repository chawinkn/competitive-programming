#include <bits/stdc++.h>
using namespace std;

int D[5009], dp[5009][5009], DP[5009];

int main () {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> D[i];
	for (int sz = 1; sz <= n; sz++) {
		for (int i = 1; i+sz-1 <= n; i++) {
			int j=i+sz-1;
			dp[i][j] = max(dp[i+1][j]+D[i], dp[i][j-1]+D[j])+abs(D[i]-D[j]);
			cout << i << " " << j << "  " << dp[i][j] << "\n";
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			DP[i] = max(DP[i], DP[j-1]+dp[j][i]);
		}
	}
	cout << DP[n];
	return 0;
}