#include <bits/stdc++.h>
using namespace std;

int dp[509][509];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	cin >> s;
	int n=s.length();
	s = ' '+s;
	for (int sz = 2; sz <= n; sz++) {
		for (int i = 1; i+sz-1 <= n; i++) {
			int j = i+sz-1;
			if (s[i] == s[j]) {
				dp[i][j] = dp[i+1][j-1]+1;
			}
			for (int k = i; k < j; k++) {
				dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]);
			}
		}
	}
	cout << n-2*dp[1][n];
	return 0;
}