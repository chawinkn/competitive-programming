#include <bits/stdc++.h>
using namespace std;

// DP + Binary Search ?

#define ll long long

ll x[509], y[509];
bool visited[509][509];
vector<vector<ll>> dp(509, vector<ll>(509, 1e18)); // minimum strength to reach j with i food

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	dp[0][1] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (k == j) continue;
				dp[i][j] = min(dp[i][j], max(dp[i-1][k], abs(x[k]-x[j])+abs(y[k]-y[j])));
			}
		}
	}
	int ans=0;
	while (m--) {
		ll s;
		cin >> s;
		for (int i = 1; i < n; i++) {
			if (s >= dp[i][n]) {
				ans += i;	
				break;
			}
		}
	}
	cout << ans;
	return 0;
}