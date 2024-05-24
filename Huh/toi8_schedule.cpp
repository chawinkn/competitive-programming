#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int a[1009], b[1009];
pair<int,int> dp[1009][1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	dp[0][0] = {1, 0};
	for (int i = 1; i <= n; i++) {
		pair<int,int> J=dp[i-1][0], K=dp[0][i-1];
		J.s += a[i], K.s += b[i];
		dp[i][0] = J, dp[0][i] = K;
		if (J.s > m) dp[i][0] = {J.f+1, a[i]};
		if (K.s > m) dp[0][i] = {K.f+1, b[i]};
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			pair<int,int> J=dp[i-1][j], K=dp[i][j-1];
			J.s += a[i], K.s += b[j];
			if (J.s > m) J = {J.f+1, a[i]};
			if (K.s > m) K = {K.f+1, b[j]};
			
			if (J.f < K.f) dp[i][j] = J;
			else if (K.f < J.f) dp[i][j] = K;
			else dp[i][j] = {J.f, min(J.s, K.s)};
		}
	}
	cout << dp[n][n].f << "\n" << dp[n][n].s;
	return 0;
}