#include <bits/stdc++.h>
using namespace std;

int dp[5009][5009];
string a, b;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> a >> b;
	a = ' '+a, b = ' '+b;
	int n=a.length(), m=b.length();
	for (int i = 1; i <= n; i++) dp[i][0] = i;
	for (int i = 1; i <= m; i++) dp[0][i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = min({dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1]+(a[i] != b[j])});
 		}
	}
	cout << dp[n][m];
	return 0;
}