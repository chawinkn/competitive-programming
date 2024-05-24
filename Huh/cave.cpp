#include <bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> E;
vector<vector<int>> dist(2009, vector<int>(2009, 1e9));

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, P, U, e, q, r, t, l, h;
	cin >> n >> P >> U >> e;
	while (e--) {
		cin >> q >> r >> t;
		E.push_back({q, r, t});
	}
	dist[P][0] = 0;
	for (int i = 1; i < n; i++) {
		for (auto [u,v,w] : E) {
			if (dist[u][i-1]+w < dist[v][i]) {
				dist[v][i] = dist[u][i-1]+w;
			}
		}
	}
	cin >> l;
	while (l--) {
		cin >> h;
		int ans=1e9;
		for (int i = 1; i < n; i++) {
			if (dist[U][i] == 1e9) continue;
			ans = min(ans, dist[U][i]+h*(i-1));
		}
		cout << ans << " ";
	}
	return 0;
}