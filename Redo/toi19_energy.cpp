#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int M=1e9+7;
int a[309];
ll dp[309][309][13], qs[309];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, K, D;
	cin >> n >> K >> D;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];	
		qs[i] = qs[i-1]+a[i];
	}
	for (int h = 1; h <= K; h++) {
		for (int sz = 1; sz <= n; sz++) {
			for (int i = 1; i+sz-1 <= n; i++) {
				int j=i+sz-1;
				if (h == 1) {
					dp[i][j][h] = 1;
					continue;
				}
				for (int k = i; k < j; k++) {
					if (abs((qs[k]-qs[i-1])-(qs[j]-qs[k])) > D) continue;
					dp[i][j][h] += dp[i][k][h-1]*dp[k+1][j][h-1];
					dp[i][j][h] %= M;
				}
			}
		}
	}
	cout << dp[1][n][K];
	return 0;
}