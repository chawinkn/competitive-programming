#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<pair<int,int>> g[10009];
vector<int> dist1(10009, INT_MAX), dist2(10009, INT_MAX);
priority_queue<pair<int,int>> pq;

int main() {
	int n, m, x, y, z, u, v, w;
	cin >> n >> m >> x >> y >> z;
	while (m--) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dist1[x] = 0;
	pq.push({0, x});
	while (!pq.empty()) {
		u = pq.top().s;
		pq.pop();
		for (auto i : g[u]) {
			v = i.f, w = i.s;
			if (dist1[u]+w < dist1[v]) {
				dist1[v] = dist1[u]+w;
				pq.push({-dist1[v], v});
			}
		}
	}
	dist2[y] = 0;
	pq.push({0, y});
	while (!pq.empty()) {
		u = pq.top().s;
		pq.pop();
		for (auto i : g[u]) {
			v = i.f, w = i.s;
			if (dist2[u]+w < dist2[v]) {
				dist2[v] = dist2[u]+w;
				pq.push({-dist2[v], v});
			}
		}
	}
	int ans=0, mn=INT_MAX;
	for (int i = 0; i < n; i++) {
		if (dist1[i] <= z && dist2[i] < mn) {
			mn = dist2[i];
			ans = i;
		}
	}
	cout << ans << " " << dist1[ans] << " " << dist2[ans];
	return 0;
}
