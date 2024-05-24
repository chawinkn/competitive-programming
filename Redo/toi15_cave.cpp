#include <bits/stdc++.h>
using namespace std;

int dist[2009][2009];
vector<tuple<int,int,int>> g;

int main() {
   	ios_base::sync_with_stdio(false); cin.tie(NULL);
   	int n, P, U, e;
   	cin >> n >> P >> U >> e;
   	while (e--) {
   		int u, v, w;
   		cin >> u >> v >> w;
   		g.push_back({u, v, w});
	}
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			dist[i][j] = 1e9;
	dist[P][0] = 0;
	for (int i = 1; i < n; i++) {
		for (auto [u,v,w] : g) {
			dist[v][i] = min(dist[v][i], dist[u][i-1]+w);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int h;
		cin >> h;
		int ans=1e9;
		for (int i = 1; i < n; i++) ans = min(ans, dist[U][i]+h*(i-1));
		cout << ans << " ";
	}
   	return 0;
}