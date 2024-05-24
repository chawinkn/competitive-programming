#include <bits/stdc++.h>
using namespace std;

// DP + Binary Search

#define ll long long

int a[200009];
ll dp[200009], mx[200009];

void solve() {
	int n; 
	ll p;
	cin >> n >> p;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l=0, r=n;
	while (l < r) {
		int m=l+(r-l+1)/2;
		memset(dp, 0, sizeof(dp));
		memset(mx, 0, sizeof(mx));
		for (int i = 1; i <= n; i++) {
			dp[i] = a[i];
			if (i >= m) dp[i] = mx[i-m]+a[i];
			dp[i] = max(dp[i], mx[i-1]);

			mx[i] = max(mx[i-1], dp[i]);
		}
		if (dp[n] >= p) l = m;
		else r = m-1;
	}
	cout << n-l << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}