#include <bits/stdc++.h>
using namespace std;

bool dp[109];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	dp[6] = dp[9] = dp[20] = true;
	for (int i = 6; i <= n; i++) {
		dp[i] |= dp[i-6] || dp[i-9] || dp[i-20];
		if (dp[i]) cout << i << "\n";
	}
	if (n < 6) cout << "no";
	return 0;
}