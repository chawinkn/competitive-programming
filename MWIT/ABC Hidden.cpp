#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
	string s;
	cin >> s;
	int n=s.length();
	ll dp[2][3]={0};
	s = ' '+s;
	for (int i = 1; i <= n; i++) {
		memset(dp[i%2], 0, sizeof(dp[i%2]));
		if (s[i] == 'A') dp[i%2][0]++;
		else if (s[i] == 'B') dp[i%2][1] += dp[(i-1)%2][0];
		else dp[i%2][2] += dp[(i-1)%2][1];
		dp[i%2][2] += dp[(i-1)%2][2], dp[i%2][1] += dp[(i-1)%2][1], dp[i%2][0] += dp[(i-1)%2][0];
	}
	cout << dp[n%2][2] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}