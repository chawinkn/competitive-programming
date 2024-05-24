#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int M=1e9+7;
ll dp[2][100009], qs[100009];
// dp[i][j] first i children used j candies

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		memset(dp[i%2], 0, sizeof(dp[i%2]));
		memset(qs, 0, sizeof(qs));
		for (int j = 0; j <= K; j++) {
			int L=j, R=j+min(a, K-j);
			qs[L] += dp[(i-1)%2][j];
			qs[R+1] -= dp[(i-1)%2][j];
//			Optimize this to prefix sum decrease O(K)
//			for (int k = 0; k <= min(a, K-j); k++) {
//				dp[i][j+k] += dp[i-1][j];
//				dp[i][j+k] %= M;
//			}
		}
		for (int j = 0; j <= K; j++) {
			if (j) qs[j] += qs[j-1];
			dp[i%2][j] += qs[j];
			dp[i%2][j] %= M;
		}
	}
	cout << dp[N%2][K];
	return 0;
}