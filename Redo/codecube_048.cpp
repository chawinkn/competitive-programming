#include <bits/stdc++.h>
using namespace std;

const int M=1e6+7;
int dp[50009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		int v;
		cin >> v;
		for (int j = m; j >= v; j--) {
			dp[j] += dp[j-v];
			dp[j] %= M;
		}
	}
	cout << dp[m];
	return 0;
}