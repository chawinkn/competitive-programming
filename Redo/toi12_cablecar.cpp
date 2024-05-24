#include <bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> e;
int parent[2509];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, s, d, p;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		e.push_back({-w, u, v});
	}
	cin >> s >> d >> p;
	sort(e.begin(), e.end());
	int mn=1e5;
	for (auto [w,u,v] : e) {
		u=find(u), v=find(v);
		if (find(s) == find(d)) break;
		if (u == v) continue;
		mn = min(mn, -w);
		parent[u] = v;
	}
	cout << p/(mn-1)+(p%(mn-1)!=0);
	return 0;
}