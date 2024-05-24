#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll qs[1000009], dp[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> qs[i], qs[i] += qs[i-1];
	int q;
	cin >> q;
	while (q--) {
		int m;
		cin >> m;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i-1]+qs[i]-qs[i-1];
			if (i >= k+1) dp[i] = min(dp[i], dp[i-k]+(qs[i]-qs[i-k])/2+m);
		}
		cout << dp[n] << "\n";
	}
	return 0;
}