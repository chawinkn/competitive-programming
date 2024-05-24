#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int parent[2503];

int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

vector<pair<int,pair<int,int>>> g;

int main() {
	int n, m, u, v, w, s, d, p;
	cin >> n >> m;
	while (m--) {
		cin >> u >> v >> w;
		g.push_back({-w, {u, v}});
	}
	cin >> s >> d >> p;
	sort(g.begin(), g.end());
	for (int i = 1; i <= n; i++) parent[i] = i;
	int mn=INT_MAX;
	for (auto i : g) {
		w=-i.f, u=i.s.f, v=i.s.s;
		u = find(u); v = find(v);
		if (find(s) == find(d)) {
			int ans=p/(mn-1);
			if (p%(mn-1) != 0) ans++;
			cout << ans;
			return 0;
		}
		if (u == v) continue;
		parent[u] = v;
		mn = min(mn, w);
	}
	return 0;
}
