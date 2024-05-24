#include <bits/stdc++.h>
using namespace std;

int card[5009], your[9], dp[5009][9][9][9][9];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= 8; i++) cin >> your[i];
	for (int i = 1; i <= n; i++) cin >> card[i];
	int ans=0;
	for (int i = 1; i <= n; i++) {
		for (int a = 1; a <= 8; a++) {
			for (int b = 1; b <= 8; b++) {
				if (b == a) continue;
				for (int c = 1; c <= 8; c++) {
					if (c == a || c == b) continue;
					for (int d = 1; d <= 8; d++) {
						if (d == a || d == b || d == c) continue;
						for (int e = 1; e <= 8; e++) {
							if (e == a || e == b || e == c || e == d) continue;
							dp[i][a][b][c][d] = max(dp[i][a][b][c][d], dp[i-1][b][c][d][e]+abs(your[a]-card[i]));
							if (i == n) ans = max(ans, dp[i][a][b][c][d]);
						}
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}