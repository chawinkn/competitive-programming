#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<ll>> dist(2009, vector<ll>(2009, 1e18));
vector<tuple<int,int,int>> E;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, s, e, m;
	cin >> n >> s >> e >> m;
	while (m--) {
		int q, r, t;
		cin >> q >> r >> t;
		E.push_back({q, r, t});
	}
	dist[s][0] = 0;
	for (int i = 1; i < n; i++) {
		for (auto [u,v,w] : E) {
			dist[v][i] = min(dist[v][i], dist[u][i-1]+w);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int h;
		cin >> h;
		ll ans=1e18;
		for (int i = 1; i < n; i++) {
			ans = min(ans, dist[e][i]+h*(i-1));
		}
		cout << ans << " ";
	}
 	return 0;   
}