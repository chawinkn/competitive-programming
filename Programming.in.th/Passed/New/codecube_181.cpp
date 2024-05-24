#include <bits/stdc++.h>
using namespace std;

int parent[40009];
vector<tuple<int,int,int>> e;
vector<pair<int,int>> c;

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u]=find(parent[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, p, x, y, z, a, b;
	cin >> n >> m >> p;
	while (m--) {
		cin >> x >> y >> z;
		e.push_back({z, x, y});
	}
	while (p--) {
		cin >> a >> b;
		c.push_back({a, b});
	}
	int l=1, r=1e9+9;
	while (l < r) {
		int k=l+(r-l+1)/2;
		bool cheat=false;
		for (int i = 1; i <= n; i++) parent[i] = i;
		for (auto [w,u,v] : e) {
			if (w >= k || find(u) == find(v)) continue;
			parent[find(u)] = find(v);
		}
		for (auto [a,b] : c) {
			if (find(a) != find(b)) continue;
			cheat = true;
			break;
		}
		if (!cheat) l = k;
		else r = k-1;
	}
	cout << (l != 1e9+9 ? l : -1);
	return 0;
}