#include <bits/stdc++.h>
using namespace std;

int dp[10009][109];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, G;
	cin >> N >> G;
	for (int i = 1; i <= N; i++) {
        int C;
        cin >> C;
        for (int j = 0; j <= G; j++) {
			dp[i][j] = max(dp[i-1][j], C);
			if (i >= 2) {
				dp[i][j] = max(dp[i][j], dp[i-2][j]+C);
				if (j >= 1) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+C);
			}
		}
    }
	cout << dp[N][G];
	return 0;
}