#include <bits/stdc++.h>
using namespace std;

vector<int> dp((1<<8)+3, INT_MAX);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, w;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w;
		int num, set=0;
		for (int j = 1, b = 1; j <= k; j++, b*=2) {
			cin >> num;
			set += num*b;
		}
		dp[set] = min(dp[set], w);
	}
	for (int i = 1; i < (1<<k); i++) {
		for (int j = 1; j < (1<<k); j++) {
			if (i == j || dp[i] == INT_MAX || dp[j] == INT_MAX) continue;
			dp[i|j] = min(dp[i|j], dp[i]+dp[j]);
		}
	}
	cout << dp[(1<<k)-1];
	return 0;
}