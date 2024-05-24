#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

vector<pii> g[100009];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> dist(100009, 1e9);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	pq.push({dist[1]=0, 1});
	while (!pq.empty()) {
		auto [d,u]=pq.top(); pq.pop();
		for (auto [v,w] : g[u]) {
			if (dist[u]+w < dist[v]) {
				pq.push({dist[v]=dist[u]+w, v});
			}
		}
	}
	while (q--) {
		int qi;
		cin >> qi;
		cout << (dist[qi] != 1e9 ? dist[qi] : -1) << "\n";
	}
	return 0;
}