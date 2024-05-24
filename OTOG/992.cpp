#include <bits/stdc++.h>
using namespace std;

// 70/100	

#define ll long long

vector<int> g[100009];
ll k, c[100009], dp[100009][3];

void dfs(int u, int p) {
	dp[u][0] = c[u]-k;
	dp[u][1] = c[u]/3;
	for (auto v : g[u]) {
		if (v == p) continue;
		dfs(v, u);
		dp[u][0] += max(dp[v][0], dp[v][1]);
		dp[u][1] += dp[v][1]/3;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, 0);
	cout << max(dp[0][0], dp[0][1]);
	return 0;
}