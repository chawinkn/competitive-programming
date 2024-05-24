#include <bits/stdc++.h>
using namespace std;

// DP

bool dp[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	cin >> s;
	int n=s.length();
	s = ' '+s;
	string ans;
	int len=0;
	for (int sz = 1; sz <= n; sz++) {
		for (int i = 1; i+sz-1 <= n; i++) {
			int j=i+sz-1;
			if (sz == 1) dp[i][j] = true;
			else if (sz == 2) dp[i][j] = (s[i] == s[j]);
			else dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
			if (dp[i][j] && sz > len) len = sz, ans = s.substr(i, sz);
		}
	}
	cout << ans;
	return 0;
}