#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int M=1e9+7;
int n, k, d, qs[309];
ll dp[309][309][11];
bool visited[309][309][11];

ll solve(int l, int r, int h) {
	if (h >= k) return 1;
	if (visited[l][r][h]) return dp[l][r][h];
	visited[l][r][h] = true;
 	for (int i = l; i < r; i++) {
		if (abs((qs[i]-qs[l-1])-(qs[r]-qs[i])) > d) continue;
		dp[l][r][h] += solve(l, i, h+1)*solve(i+1, r, h+1);
		dp[l][r][h] %= M;
	}
	return dp[l][r][h];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k >> d;
	for (int i = 1; i <= n; i++) {
		cin >> qs[i];
		qs[i] += qs[i-1];
	}
	cout << solve(1, n, 1);
	return 0;
}