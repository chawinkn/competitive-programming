#include <bits/stdc++.h>
using namespace std;

int p[100009];

int find(int u) {
	if (u == p[u]) return u;
	return p[u]=find(p[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) p[i] = i;
	while (m--) {
		int u, v;
		cin >> u >> v;
		u = find(u), v = find(v);
		if (u == v) continue;
		p[u] = v;
	}
	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		u = find(u), v = find(v);
		cout << (p[u] == p[v] ? "true" : "false") << "\n";
	}
	return 0;
}