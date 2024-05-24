#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int J[1009], K[1009];
pair<int,int> dp[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) cin >> J[i];
	for (int i = 1; i <= n; i++) cin >> K[i];
	dp[0][0] = {1, 0};
	for (int i = 1; i <= n; i++) {
		if (dp[0][i-1].s+K[i] <= m) dp[0][i] = {dp[0][i-1].f, dp[0][i-1].s+K[i]};
		else dp[0][i] = {dp[0][i-1].f+1, K[i]};
		if (dp[i-1][0].s+J[i] <= m) dp[i][0] = {dp[i-1][0].f, dp[i-1][0].s+J[i]};
		else dp[i][0] = {dp[i-1][0].f+1, J[i]};
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			pair<int,int> fromk, fromj;
			if (dp[i][j-1].s+K[j] <= m) fromk = {dp[i][j-1].f, dp[i][j-1].s+K[j]};
			else fromk = {dp[i][j-1].f+1, K[j]};
			if (dp[i-1][j].s+J[i] <= m) fromj = {dp[i-1][j].f, dp[i-1][j].s+J[i]};
			else fromj = {dp[i-1][j].f+1, J[i]};
			dp[i][j] = min(fromk, fromj);
		}
	}
	cout << dp[n][n].f << "\n" << dp[n][n].s;
	return 0;
}