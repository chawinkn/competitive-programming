#include<bits/stdc++.h>
using namespace std;

// DP

#define ll long long

const int M = 1e9+7;

ll dp[5009][9];
char s[9][5009];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < 2; i++) cin >> (s[i]+1);
	memset(dp, 0, sizeof(dp));
	dp[0][0] = dp[0][1] = 1;
	for (int i = 1; i <= n; i++) {
		if (s[0][i] == '.' && s[1][i] == '.') {
			dp[i][0] = (dp[i-1][0]+dp[i-1][1])%M;
			dp[i][1] = dp[i][0];
		}
		else if (s[0][i] == '.' && s[1][i] == '#') dp[i][0] = dp[i-1][0];
		else if (s[0][i] == '#' && s[1][i] == '.') dp[i][1] = dp[i-1][1];
	}
	cout << (dp[n][0]+dp[n][1])%M << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}