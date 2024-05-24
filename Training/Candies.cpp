#include <bits/stdc++.h>
using namespace std;

// 80/100 (ผิดไหนไม่รู้)

const int M=1e9+7;
#define ll long long

ll dp[109][100009], qs[100009];
int a[109];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, K;
	cin >> n >> K;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		memset(qs, 0, sizeof(qs));
		qs[0] = dp[i-1][0];
		for (int j = 1; j <= K; j++) {
			qs[j] += qs[j-1], qs[j] %= M;
			qs[j] += dp[i-1][j], qs[j] %= M;
		}
		for (int j = 0; j <= K; j++) {
			dp[i][j] += qs[j], dp[i][j] %= M;
			if (j > a[i]) dp[i][j] -= qs[j-a[i]-1], dp[i][j] %= M;
		}
	}
	cout << dp[n][K];
	return 0;
}