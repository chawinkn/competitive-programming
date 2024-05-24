#include <bits/stdc++.h>
using namespace std;

const int M=1e9+7;
#define ll long long

ll dp[100009][3];
vector<int> g[100009];
bool visited[100009];

void dfs(int u) {
	visited[u] = true;
	dp[u][0] = dp[u][1] = 1;
	for (auto v : g[u]) {
		if (visited[v]) continue;
		dfs(v);
		dp[u][0] *= (dp[v][0]+dp[v][1]) % M, dp[u][0] %= M;
		dp[u][1] *= dp[v][0], dp[u][1] %= M;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n-1; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs(1);
	cout << (dp[1][0]+dp[1][1]) % M;
	return 0;
}