#include <bits/stdc++.h>
using namespace std;

// All pair shortest path

vector<vector<int>> dist(309, vector<int>(309, 1e9));

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int s, e, w;
		cin >> s >> e >> w;
		dist[s][e] = min(dist[s][e], w);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (dist[i][j] != 1e9 ? dist[i][j] : 0) << " ";
		}
		cout << "\n";
	}
	return 0;
}