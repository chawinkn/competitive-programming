#include <bits/stdc++.h>
using namespace std;

bool P[5009][5009];
int dp[5009][5009];
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;
	int n=s.length();
	s = ' '+s;
	for (int sz = 1; sz <= n; sz++) {
		for (int i = 1; i+sz-1 <= n; i++) {
			int j=i+sz-1;
			if (sz == 1) {
				P[i][j] = true, dp[i][j] = 1;
				continue;
			}

			if (sz == 2) P[i][j] = (s[i] == s[j]);
			else P[i][j] = P[i+1][j-1] && (s[i] == s[j]);
			dp[i][j] = dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1]+P[i][j];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << dp[l][r] << "\n";
	}
	return 0;
}