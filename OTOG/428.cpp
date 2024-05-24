#include <bits/stdc++.h>
using namespace std;

const int M = 1e8+3;
int dp[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int s1, s2;
	cin >> s1 >> s2;
	s1++, s2++;
	dp[0][1] = 1;
	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			dp[i][j] = (dp[i-1][j]+dp[i][j-1])%M;
		}
	}
	cout << dp[s1][s2];
	return 0;
}