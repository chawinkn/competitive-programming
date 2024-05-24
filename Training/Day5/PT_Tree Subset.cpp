#include <bits/stdc++.h>
using namespace std;

// DP on Trees

#define ll long long

int V[100009];
ll dp[100009][2];
bool visited[100009];
vector<int> g[100009];

void dfs(int u) {
	visited[u] = true;
	dp[u][1] = V[u];
	for (auto v : g[u]) {
		if (visited[v]) continue;
		dfs(v);
		dp[u][0] += max(dp[v][0], dp[v][1]);
		dp[u][1] += dp[v][0]; 
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> V[i];
	for (int i = 1; i <= n-1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	memset(dp, 0, sizeof(dp));
	memset(visited, false, sizeof(visited));
	dfs(1);
	cout << max(dp[1][0], dp[1][1]) << "\n";
	for (int i = 1; i <= n; i++) g[i].clear();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}