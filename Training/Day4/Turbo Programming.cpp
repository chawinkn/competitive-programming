#include <bits/stdc++.h>
using namespace std;

// Shortest path

#define pii pair<int,int>

vector<pii> g[1009];
vector<int> dist(1009, 1e9);
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	while (m--) {
		int s, e, w;
		cin >> s >> e >> w;
		g[s].push_back({e, w});
	}
	pq.push({dist[1]=0, 1});
	while (!pq.empty()) {
		int u=pq.top().second; pq.pop();
		for (auto i : g[u]) {
			int v=i.first, w=i.second;
			if (dist[u]+w < dist[v]) {
				pq.push({dist[v]=dist[u]+w, v});
			}
		}
	}
	while (q--) {
		int c;
		cin >> c;
		cout << (dist[c] != 1e9 ? dist[c] : -1) << "\n";
	}
	return 0;
}