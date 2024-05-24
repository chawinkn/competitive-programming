#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll arr[5009];
vector<ll> dp(5009, vector<ll>(5009, -1));

ll solve(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l < 1 || l > r || r > n) return 0;
	
	dp[l][r] = max(
		min(solve(l+2, r), solve(l+1, r-1))+arr[l], 
		min(solve(l+1, r-1), solve(l, r-2))+arr[r]
	);
	
	return dp[l][r];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cout << solve(1, n);
	return 0;
}
