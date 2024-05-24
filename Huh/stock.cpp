#include <bits/stdc++.h>
using namespace std;

int dp[1000009], p[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(0, p[i]-p[i-1])+dp[i-1];
		cout << dp[i] << " ";
	}
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
//		cout << dp[b]-dp[a] << "\n";
	}
	return 0;
}