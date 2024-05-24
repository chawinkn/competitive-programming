#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[409][409]; // best answer from compress time index i j
int cost[409][409];

void solve() {
	int n;
	cin >> n;
	vector<int> l(n+1), r(n+1), c(n+1);
	memset(dp, 0, sizeof(dp));
	memset(cost, 0, sizeof(cost));
	map<int,int> mp;
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i] >> c[i];
		mp[l[i]] = mp[r[i]] = 0;
	}
	int idx=0;
	for (auto &i : mp) i.second = ++idx;
	for (int i = 1; i <= n; i++) cost[mp[l[i]]][mp[r[i]]] = c[i];
	// compress idx
	for (int sz = 1; sz <= idx; sz++) {
		for (int i = 1; i+sz-1 <= idx; i++) {
			int j=i+sz-1;
			for (int k = i; k <= j; k++) {
				dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]);
			}
			dp[i][j] += cost[i][j];
		}
	}
	cout << dp[1][idx] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}