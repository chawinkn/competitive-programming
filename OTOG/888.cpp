#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int countWays(int N, int M, vector<int> S){
	vector<int> dp(N+1);
	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (i >= S[j]) dp[i] += dp[i-S[j]], dp[i] %= MOD;
		}
	}
    return dp[N];
}

// int main() {
// 	cout << countWays(5, 2, {1,2});
// 	return 0;
// }