#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M=1e9+7;

int qs[309];
ll dp[309][309][13];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, K, D;
	cin >> n >> K >> D;
	for (int i = 1; i <= n; i++) cin >> qs[i], qs[i] += qs[i-1];
	for (int h = K; h >= 1; h--) {
		for (int sz = 1; sz <= n; sz++) {
			for (int i = 1; i+sz-1 <= n; i++) {
				int j=i+sz-1;
				if (h == K) {
					dp[i][j][h] = 1;
					continue;
				}
				for (int k = i; k < j; k++) {
					int L=qs[k]-qs[i-1], R=qs[j]-qs[k];
					if (abs(L-R) > D) continue;
					dp[i][j][h] += dp[i][k][h+1]*dp[k+1][j][h+1];
					dp[i][j][h] %= M;
				}
			}
		}
	}
	cout << dp[1][n][1];
	return 0;
}