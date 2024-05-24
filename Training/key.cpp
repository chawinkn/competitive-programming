#include <bits/stdc++.h>
using namespace std;

string s, s1, s2;
bool dp[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int k;
	cin >> s1 >> s2 >> k;
	int n=s1.length(), m=s2.length();
	s1 = ' '+s1, s2 = ' '+s2;
	while (k--) {
		cin >> s;
		s = ' '+s;
		for (int i = 0; i <= n; i++) { // s1
			for (int j = 0; j <= m; j++) { // s2
				if (i == 0 && j == 0) dp[i][j] = true;
				else dp[i][j] = false;
				if (i >= 1) dp[i][j] |= dp[i-1][j] && s[i+j] == s1[i];
				if (j >= 1) dp[i][j] |= dp[i][j-1] && s[i+j] == s2[j];
			}
		}
		cout << (dp[n][m] ? "Yes" : "No") << "\n";
	}
	return 0;
}