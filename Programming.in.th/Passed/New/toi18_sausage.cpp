#include <bits/stdc++.h>
using namespace std;

int n, d[5009], dp[5009][5009], ans[5009];

int solve(int l, int r) {
	if (l == r) return d[l];
	if (dp[l][r]) return dp[l][r];
	
	dp[l][r] = abs(d[l]-d[r])+max(solve(l+1,r)+d[l], solve(l,r-1)+d[r]);
	return dp[l][r];
}

int cut(int l) {
	if (l > n) return 0;
	if (ans[l]) return ans[l];
	
	for (int i = l; i <= n; i++) {
		ans[l] = max(ans[l], dp[l][i]+cut(i+1));
	}
	return ans[l];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> d[i];	
	solve(1, n);
	cout << cut(1);
	return 0;
}