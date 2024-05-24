#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

vector<pii> g[(1<<19)+9];
vector<int> poison, dist((1<<19)+9, 1e9);
priority_queue<pii, vector<pii>, greater<pii>> pq; 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		int w;
		cin >> w;
		int pset=0, aset=0;
		for (int j = 0; j < s; j++) {
			int p;
			cin >> p;
			if (p == -1) pset |= 1<<j;
			else if (p == 1) aset |= 1<<j;
		}
		g[pset].push_back({aset, w});
		poison.push_back(pset);
	}
	for (int i = 0; i < 1<<s; i++) {
		for (int j = 0; j < s; j++) {
			if (i&(1<<j)) g[i].push_back({i^(1<<j), 0});
		}
	}
	pq.push({dist[0]=0, 0});
	while (!pq.empty()) {
		auto [d,u]=pq.top(); pq.pop();
		for (auto [v,w] : g[u]) {
			if (dist[u]+w < dist[v]) {
				pq.push({dist[v]=dist[u]+w, v});
			}
		}
	}
	int ans=0;
	for (auto pset : poison) {
		if (dist[pset] == 1e9) continue;
		ans = max(ans, dist[pset]);
	}
	cout << ans;
	return 0;
}