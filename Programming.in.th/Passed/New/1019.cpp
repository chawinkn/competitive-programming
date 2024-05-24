#include <bits/stdc++.h>
using namespace std;

int dp[209][209];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	int n=a.length(), m=b.length(), ans=0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i-1] != b[j-1]) continue;
			dp[i][j] = 1+dp[i-1][j-1];
			ans = max(ans, dp[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] == ans) {
				for (int k = i-ans+1; k <= i; k++) cout << a[k-1];
				return 0;
			}
		}
	}
	return 0;
}
