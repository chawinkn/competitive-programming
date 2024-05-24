#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX_N=3e3+9;
ll arr[MAX_N], dp[MAX_N][MAX_N];

//ll solve(int l, int r) {
//	if (l > r) return 0;
//	if (dp[l][r]) return dp[l][r];
//	
//	dp[l][r] = max(arr[l]+min(solve(l+2, r), solve(l+1, r-1)), arr[r]+min(solve(l+1, r-1), solve(l, r-2)));
//	return dp[l][r];
//}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	ll sum=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum += arr[i];	
	}
//	ll x=solve(1, n);
	for (int sz = 1; sz <= n; sz++) {
		for (int i = 1; i <= n-sz+1; i++) {
			int j=i+sz-1;
			dp[i][j] = max(arr[i]+min(dp[i+2][j], dp[i+1][j-1]), arr[j]+min(dp[i+1][j-1], dp[i][j-2]));
		}
	}
	ll x=dp[1][n];
	ll y=sum-x;
	cout << x-y;
	return 0;
}
