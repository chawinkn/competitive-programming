#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

void solve() {
	int n, m, s, e, t, p;
	cin >> n >> m >> s >> e >> t >> p;
	vector<int> peat(p);
	for (int i = 0; i < p; i++) cin >> peat[i];
	vector<pii> g[n+1];
	map<pii,pii> closure;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	int ptime=0;
	for (int i = 0; i < p-1; i++) {
		int U=peat[i], V=peat[i+1], W;
		for (auto [v,w] : g[U]) {
			if (v == V) {
				W = w;
				break;
			}
		}
		closure[{U, V}] = closure[{V, U}] = {ptime, ptime+W-1};
		// cout << U << "->" << V << " " << ptime << "-" << ptime+W-1 << "\n";
		ptime += W;
	}
	vector<int> dist(n+1, 1e9);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<bool> visited(n+1);
	pq.push({dist[s]=t, s});
	while (!pq.empty()) {
		auto [d,u]=pq.top(); pq.pop();
		if (visited[u]) continue;
		visited[u] = true;
		for (auto [v,w] : g[u]) {
			if (closure.find({u, v}) != closure.end()) {
				auto [l,r] = closure[{u, v}];
				// ถึงตอนถนนยังไม่ปิด เข้าถนนไปก่อนได้ (จะได้ไปต่อได้เลยไม่ต้องรอ)
				if (dist[u] < l) {
					if (dist[u]+w < dist[v]) pq.push({dist[v]=dist[u]+w, v});
					continue;
				}
				// ถึงตอนถนนปิดแล้ว
				else if (dist[u] >= l && dist[u] <= r) {
					if (r+w+1 < dist[v]) pq.push({dist[v]=r+w+1, v});
					continue;
				}
				// เลยช่วงที่ปิดถนนไปแล้ว คิดปกติ
				// else {
				// 	if (dist[u]+w < dist[v]) pq.push({dist[v]=dist[u]+w, v});
				// 	continue;
				// }
			}
			if (dist[u]+w < dist[v]) pq.push({dist[v]=dist[u]+w, v});
		}
	}
	// for (int i = 1; i <= n; i++) cout << i << " " << dist[i] << "\n";
	cout << dist[e]-t << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}