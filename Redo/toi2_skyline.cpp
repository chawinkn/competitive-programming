#include <bits/stdc++.h>
using namespace std;

int dp[259];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, l, h, r;
	cin >> n;
	int mn=255, mx=1;
	for (int i = 1; i <= n; i++) {
		cin >> l >> h >> r;
		mn = min(mn, l); mx = max(mx, r);
		for (int j = l; j < r; j++) dp[j] = max(dp[j], h);
	}
	for (int i = mn; i <= mx; i++) {
		if (dp[i] != dp[i-1]) cout << i << " " << dp[i] << " ";	
	}
	return 0;
}