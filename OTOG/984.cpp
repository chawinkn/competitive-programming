#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[10009];
vector<int> dist(10009, 1e9);
priority_queue<pair<int,int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, q, k, p, s;
	cin >> n >> m >> q >> k >> p >> s;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
	}	
	dist[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		auto [dd,u]=pq.top(); pq.pop();
		for (auto [v,w] : g[u]) {
			int d=(u != p ? dist[u] : 0);
			if (d+w < k && d+w < dist[v]) {
				dist[v] = d+w;
				pq.push({-dist[v], v});
			}
		}
	}
	while (q--) {
		int t;
		cin >> t;
		if (k >= dist[t]) {
			if (t == p) cout << k;
			else cout << k-dist[t];
		}
		else cout << -1;
		cout << "\n";
	}
	return 0;
}