#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll x[5009], dp[5009][5009];
bool visited[5009][5009];

ll solve(int l, int r) {
	if (l > r) return 0;
	if (visited[l][r]) return dp[l][r];
	visited[l][r] = true;
	return dp[l][r]=max(min(solve(l+2,r),solve(l+1,r-1))+x[l], min(solve(l,r-2),solve(l+1,r-1))+x[r]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i];
	cout << solve(1, n);
	return 0;
}