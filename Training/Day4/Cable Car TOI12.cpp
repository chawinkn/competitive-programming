#include <bits/stdc++.h>
using namespace std;

// MST

int p[200009];
vector<tuple<int,int,int>> E;

int find(int u) {
	if (u == p[u]) return u;
	return p[u]=find(p[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		E.emplace_back(-w, u, v);
	}
	int s, d, P;
	cin >> s >> d >> P;
	iota(p+1, p+n+1, 1);
	sort(E.begin(), E.end());
	int mn=1e5;
	for (auto i : E) {
		int w, u, v;
		tie(w, u, v) = i;
		if (find(s) == find(d)) break;
		u = find(u), v = find(v);
		if (u == v) continue;
		p[u] = v;
		mn = min(mn, -w);
	}
	cout << P/(mn-1)+(P%(mn-1)!=0);
	return 0;
}