#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int parent[100009];
vector<pair<int,pair<int,int>>> g;
priority_queue<int> pq;

int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k, u, v, w;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		g.push_back({w, {u, v}});
	}
	sort(g.begin(), g.end());
	for (auto i : g) {
		u=find(i.s.f), v=find(i.s.s);
		if (u == v) continue;
		parent[u] = v;
		pq.push(i.f);
	}
	int ans=0;
	while (k > 0 && !pq.empty()) {
		int mx=pq.top(); pq.pop();
		if (mx/2 != 0) pq.push(mx/2);
		k--;
	}
	while (!pq.empty()) ans += pq.top(), pq.pop();
	cout << ans;
	return 0;
}
