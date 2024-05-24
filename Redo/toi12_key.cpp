#include <bits/stdc++.h>
using namespace std;

bool dp[1009][1009];
string s, s1, s2;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> s1 >> s2 >> q;
	int m=s1.length(), n=s2.length();
	s1 = ' '+s1, s2 = ' '+s2; 
	while (q--) {
		cin >> s;
		s = ' '+s;
		for (int i = 0; i <= m; i++) for (int j = 0; j <= n; j++) dp[i][j] = false;
		dp[0][0] = true;
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				if (i >= 1) dp[i][j] |= (dp[i-1][j] && s1[i] == s[i+j]);
				if (j >= 1) dp[i][j] |= (dp[i][j-1] && s2[j] == s[i+j]);
			}
		}
		cout << (dp[m][n] ? "Yes" : "No") << "\n";
	}
	return 0;
}