#include <bits/stdc++.h>
using namespace std;

// DP + Quicksum 2D ?

#define ll long long

const int M=1e9+7;
bool has[509][100009];
ll a[100009], b[100009], dp[509][100009], qs[509][100009];
map<ll,int> mp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i];
		mp[b[i]] = 0;
	}
	int idx=1;
	for (auto &i : mp) i.second = idx++;
	for (int i = 1; i <= m; i++) {
		int idx=mp[b[i]];
		has[a[i]][idx] = true;
		dp[a[i]][idx]++;
	}
	idx--;
	// dp[i][j] cnt of cat type 1-i max level j
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= idx; j++) {
			// Pick
			dp[i][j] += dp[i][j]*qs[i-1][j-1], dp[i][j] %= M;
			// Not Pick
			dp[i][j] += dp[i-1][j], dp[i][j] %= M;
			
			qs[i][j] += qs[i][j-1], qs[i][j] %= M;
			qs[i][j] += dp[i][j], qs[i][j] %= M;
			// cout << dp[i][j] << " ";
		}
		// cout << "\n";
	}
	cout << qs[n][idx];
	return 0;
}