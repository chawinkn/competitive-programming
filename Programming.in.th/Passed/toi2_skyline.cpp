#include <bits/stdc++.h>
using namespace std;

int dp[256];

int main() {
	int n, l, h, r, ml=256, mr=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> h >> r;
		ml = min(ml, l);
		mr = max(mr, r);
		for (int j = l; j < r; j++) dp[j] = max(dp[j], h);
	}
	for (int i = ml; i <= mr; i++) {
		if (dp[i] != dp[i-1]) {
			cout << i << " " << dp[i] << " ";	
		}
	}
	return 0;
}
