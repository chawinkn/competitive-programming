#include <bits/stdc++.h>
using namespace std;

#define ll long long

// 32/100

int n, m, K, E[709], p[709][1009], sz[709][1009];
int dp[709][709];
bool visited[709][709];

int find(int i, int u) {
	if (u == p[i][u]) return u;
	return p[i][u]=find(i, p[i][u]);
}

int solve(int no, int warp) {
	if (warp > K) return 0;
	if (visited[no][warp]) return dp[no][warp];
	visited[no][warp] = true;
	for (int i = no+1; i <= m; i++) {
		dp[no][warp] = max(dp[no][warp], solve(i, warp+1));
	}
	dp[no][warp] += sz[no][find(no, 1)];
	return dp[no][warp];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> K;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) p[i][j] = j, sz[i][j] = 1;
		cin >> E[i];
		for (int j = 0; j < E[i]; j++) {
			int u, v;
			cin >> u >> v;
			u = find(i, u), v = find(i, v);
			if (u == v) continue;
			p[i][u] = v;
			sz[i][v] += sz[i][u];
		}
	}
	cout << solve(1, 0);
	return 0;
}