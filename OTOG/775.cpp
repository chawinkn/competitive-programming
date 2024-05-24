#include <bits/stdc++.h>
using namespace std;

#define ll long long

int c[509], cnt[509][509];
ll dist[509][509];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = c[i]+c[j];
			cnt[i][j] = 2;
		}
	}
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		dist[u][v] = dist[v][u] = min(dist[u][v], (ll)w);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k]+dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k]+dist[k][j];
					cnt[i][j] = cnt[i][k]+cnt[k][j];
				}
				else if (dist[i][k]+dist[k][j] == dist[i][j]) {
					cnt[i][j] = max(cnt[i][j], cnt[i][k]+cnt[k][j]);
				}
			}
		}
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << dist[u][v] << " " << cnt[u][v] << "\n";
	}
	return 0;
}