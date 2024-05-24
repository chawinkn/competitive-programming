#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll x[509], y[509], dp[509][509];
// dp[i][j] minimum strength to reach node j with i food

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j] = 1e18;
	dp[0][1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (k == j) continue;
				dp[i][j] = min(dp[i][j], max(dp[i-1][k], abs(x[j]-x[k])+abs(y[j]-y[k])));
			}
		}
	}
	vector<ll> res;
	for (int i = 1; i < n; i++) res.push_back(dp[i][n]);
	ll ans=0;
	while (m--) {
		ll s;
		cin >> s;
		// first element <= s
		ans += lower_bound(res.begin(), res.end(), s, greater<ll>())-res.begin()+1;
	}
	cout << ans;
	return 0;
}