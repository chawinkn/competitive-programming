#include <bits/stdc++.h>
using namespace std;

int dist[209][209], arr[19];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k, u, v, w;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) cin >> arr[i];
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = 1e6;
		}
	}
	while (m--) {
		cin >> u >> v >> w;
		dist[u][v] = w;
		dist[v][u] = w;
	}
	for (int x = 1; x <= n; x++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][x]+dist[x][j]);
			}
		}
	}
	
	return 0;
}
