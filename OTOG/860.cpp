#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int M=1e9+7;
int x, l, dp[159][2509];
vector<pair<int,char>> g[159];
string s;

int solve(int u, int i) {
	if (i >= l) return dp[u][i] = 1;
	if (dp[u][i]) return dp[u][i];
	for (auto [v,c] : g[u]) {
		if (c != s[i]) continue;
		dp[u][i] += solve(v, i+1);
		dp[u][i] %= M;
	}
	return dp[u][i];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b; char c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
	}
	cin >> x >> l >> s;
	cout << solve(x, 0);
	return 0;
}