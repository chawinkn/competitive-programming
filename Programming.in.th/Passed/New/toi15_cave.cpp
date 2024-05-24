#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[2009], temp;
vector<vector<int>> dist(2009, vector<int>(2009, 1e9));
bool visited[2009][2009];
queue<tuple<int,int,int>> Q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, P, U, e, q, r, t, l, h;
	cin >> n >> P >> U >> e;
	while (e--) {
		cin >> q >> r >> t;
		g[q].push_back({r, t});
	}
	cin >> l;
	dist[P][0] = 0;
	Q.push({0, P, 0});
	while (!Q.empty()) {
		auto [d,u,cnt]=Q.front(); Q.pop();
		if (visited[u][cnt]) continue;
		visited[u][cnt] = true;
		if (cnt >= n) continue;
		for (auto [v,w] : g[u]) {
			if (dist[u][cnt]+w < dist[v][cnt+1]) {
				dist[v][cnt+1] = dist[u][cnt]+w;
				Q.push({-dist[v][cnt+1], v, cnt+1});
			}
		}
	}
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