#include <bits/stdc++.h>
using namespace std;

int dp[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) {
		string s1, s2;
		cin >> s1 >> s2;
		memset(dp, 0, sizeof(dp));
		int n=s1.length(), m=s2.length();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (s1[i-1] == s2[j-1]) {
					dp[i][j] = dp[i-1][j-1]+1;
				}
				else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		cout << 15*(n-dp[n][m])+30*(m-dp[n][m]) << "\n";
	}
	return 0;
}