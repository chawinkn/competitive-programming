#include <bits/stdc++.h>
using namespace std;

#define ll long long

int w[109], v[109];
ll dp[2][100009];
// dp[i][j] minimum weight sum up to j using first i

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, W, sum=0;
	cin >> N >> W;
	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> v[i];
		sum += v[i];
	}
	for (int j = 1; j <= sum; j++) dp[0][j] = dp[1][j] = 1e9;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= sum; j++) {
			dp[i%2][j] = min(dp[i%2][j], dp[(i-1)%2][j]);
			if (j < v[i]) continue;
			dp[i%2][j] = min(dp[i%2][j], dp[(i-1)%2][j-v[i]]+w[i]);
		}
	}
	for (int i = sum; i >= 1; i--) {
		if (dp[N%2][i] <= W) {
			cout << i;
			break;
		}
	}
	return 0;
}