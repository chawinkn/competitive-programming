#include <bits/stdc++.h>
using namespace std;

int p[100009], cnt[100009];

int find(int u) {
	if (u == p[u]) return u;
	return p[u]=find(p[u]);
}

vector<pair<int,int>> temp[2];
vector<int> g[100009];

void dfs(int u) {
	if (cnt[u]) return;
	cnt[u] = 1;
	for (auto v : g[u]) {
		dfs(v);
		cnt[u] = max(cnt[u], cnt[v]+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) p[i] = i;
	while (m--) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		if (c == '=') {
			a = find(a), b = find(b);
			if (a == b) continue;
			p[a] = b;
		}
		else if (c == '>') temp[0].push_back({a, b});
		else temp[1].push_back({b, a});
	}
	for (int i = 0; i < 2; i++) {
		for (auto [u,v] : temp[i]) g[find(u)].push_back(find(v));
	}
	for (int i = 1; i <= n; i++) {
		int u = find(i);
		dfs(u);
		cout << cnt[u] << "\n";
	}
	return 0;
}