#include <bits/stdc++.h>
using namespace std;

int N, C[509], dp[509][29][29];

int solve(int i, int C1, int C2) {
	if (i > N) return dp[i][C1][C2]=0;
	if (dp[i][C1][C2] != -1) return dp[i][C1][C2];
	if (C1 == C[i] || C2 == C[i]) dp[i][C1][C2] = solve(i+1, C1, C2);
	else dp[i][C1][C2] = min(solve(i+1, C[i], C2), solve(i+1, C1, C[i]))+1;
	return dp[i][C1][C2];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int Q;
	cin >> Q;
	while (Q--) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> C[i];
		memset(dp, -1, sizeof(dp));
		cout << solve(1, 0, 0) << "\n";
	}
	return 0;
}