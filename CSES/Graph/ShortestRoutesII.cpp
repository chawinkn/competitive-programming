#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<ll>> dist(509, vector<ll>(509, 1e12));

int main() {
	int n, m, q, a, b;
	ll c;
	cin >> n >> m >> q;
	while (m--) {
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = min(dist[b][a], c);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
				else dist[i][j] = 0;
			}
		}
	}
	while (q--) {
		cin >> a >> b;
		if (dist[a][b] != 1e12) cout << dist[a][b];
		else cout << -1;
		cout << "\n";
	}
	return 0;
}
