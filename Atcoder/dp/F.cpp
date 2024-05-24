#include <bits/stdc++.h>
using namespace std;

int dp[3009][3009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s, t;
	cin >> s >> t;
	int n=s.length(), m=t.length();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	stack<char> ans;
	int i=n, j=m;
	while (i > 0 && j > 0) {
		if (s[i-1] == t[j-1]) {
			ans.push(s[i-1]);
			i--, j--;
			continue;
		}
		if (dp[i-1][j] > dp[i][j-1]) i--;
		else j--;
	}
	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
	return 0;
}
