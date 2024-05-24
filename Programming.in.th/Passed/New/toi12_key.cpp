#include <bits/stdc++.h>
using namespace std;

string s1, s2, s;
bool dp[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int k;
	cin >> s1 >> s2 >> k;
	int n=s1.length(), m=s2.length();
	s1 = ' '+s1,  s2 = ' '+s2;
	while (k--) {
		cin >> s;
		s = ' '+s;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) dp[i][j] = false;
		}
		dp[0][0] = true;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (i >= 1) dp[i][j] |= (dp[i-1][j] && s1[i] == s[i+j]);
				if (j >= 1) dp[i][j] |= (dp[i][j-1] && s2[j] == s[i+j]);
			}
		}
		cout << (dp[n][m] ? "Yes" : "No") << "\n";
	}
	return 0;
}