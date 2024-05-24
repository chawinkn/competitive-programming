#include <bits/stdc++.h>
using namespace std;

// DP on Trees

int n, k, T[5009], dp[5009][109];
bool visited[5009][109];

int solve(int u, int left) {
	if (u > n || left == 0) return 0;
	if (visited[u][left]) return dp[u][left];
	visited[u][left] = true;
	for (int i = 0; left-i-1 >= 0; i++) {
		dp[u][left] = max(dp[u][left], solve(2*u, i)+solve(2*u+1, left-i-1)+T[u]);
	}
	return dp[u][left];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> T[i];
	int ans=0;
	for (int i = 1; i <= n; i++) ans = max(ans, solve(i, k));
	cout << ans;
	return 0;
}