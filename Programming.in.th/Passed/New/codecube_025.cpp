#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll arr[609], qs[609], dp[609][609];

ll solve(int l, int r) {
	if (dp[l][r]) return dp[l][r];
	if (l == r) return 0;
	
	for (int i = l; i < r; i++) {
		ll a = qs[i]-qs[l-1];
		ll b = qs[r]-qs[i];
		ll score = 2*min(a, b)+max(a, b);
		dp[l][r] = max(dp[l][r], solve(l, i)+solve(i+1, r)+score);
	}
	return dp[l][r];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		qs[i] = qs[i-1]+arr[i];
	}
	cout << solve(1, n);
	return 0;
}
