#include <bits/stdc++.h>
using namespace std;

int dp[10009][109];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, g, x;
	cin >> n >> g;
	for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j <= g; j++) {
            dp[i][j] = max(dp[i-1][j], (i >= 2 ? dp[i-2][j] : 0) + x);
            if (j >= 1)
                dp[i][j] = max({dp[i][j], dp[i-1][j-1] + x, (i >= 2 ? dp[i-2][j-1] : 0) + x});
        }
    }
	cout << dp[n][g];
	return 0;
}