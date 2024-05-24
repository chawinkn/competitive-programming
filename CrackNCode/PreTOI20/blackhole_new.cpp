#include <bits/stdc++.h>
using namespace std;

int p[1009], sz[1009], dp[1009][709], ndp[1009][709];

int find(int u) {
	if (u == p[u]) return u;
	return p[u]=find(p[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, K;
	cin >> n >> m >> K;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= K; j++) dp[i][j] = ndp[i][j] = -1e9;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) p[j] = j, sz[j] = 1;
		int E;
		cin >> E;
		while (E--) {
			int u, v;
			cin >> u >> v;
			u = find(u), v = find(v);
			if (u == v) continue;
			p[u] = v;
			sz[v] += sz[u];
		}
		if (i == 1) {
			for (int j = 1; j <= n; j++) {
				if (find(1) != find(j)) continue;
				dp[j][0] = sz[find(1)];
			}
		}
		else {
			for (int j = 1; j <= n; j++) {
				int u=find(j);
				for (int k = 1; k <= K; k++) {
					ndp[u][k] = max(ndp[u][k], dp[j][k-1]+sz[u]);
				}
			}
			for (int j = 1; j <= n; j++) {
				int u=find(j);
				for (int k = 1; k <= K; k++) {
					dp[j][k] = max(dp[j][k], ndp[u][k]);
				}
			}
		}
	}
	int ans=0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= K; j++) ans = max(ans, dp[i][j]);
	}
	cout << ans;
	return 0;
}