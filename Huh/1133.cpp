#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dist(509, vector<int>(509, 1e9));
vector<int> line[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, q;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int s;
		cin >> s;
		for (int j = 0; j < s; j++) {
			int u;
			cin >> u;
			line[u].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (auto j : line[i]) {
			for (auto k : line[i]) {
				if (j == k) dist[j][k] = 0;
				else dist[j][k] = 1;
			}
		}
	}
	for (int k = 1; k <= m; k++) {	
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		int ans=1e9;
		for (auto i : line[a]) {
			for (auto j : line[b]) {
				ans = min(ans, dist[i][j]);
			}
		}
		if (ans == 1e9) cout << "impossible\n";
		else cout << ans << "\n";
	}
	return 0;
}