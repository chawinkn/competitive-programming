#include <bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> E;
vector<pair<int,int>> P;
int parent[40009];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u]=find(parent[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, p;
	cin >> n >> m >> p;
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		E.push_back({z, x, y});
	}
	sort(E.begin(), E.end());
	while (p--) {
		int a, b;
		cin >> a >> b;
		P.push_back({a, b});
	}
	int l=1, r=1e9+9;
	while (l < r) {
		int mid=l+(r-l+1)/2;
		iota(parent+1, parent+n+1, 1);
		for (auto [w,u,v] : E) {
			if (w >= mid) break;
			u = find(u), v = find(v);
			if (u == v) continue;
			parent[u] = v;
		}
		bool copying=false;
		for (auto [u,v] : P) {
			if (find(u) == find(v)) {
				copying = true;
				break;
			}
		}
		if (!copying) l = mid;
		else r = mid-1;
	}
	cout << (l != 1e9+9 ? l : -1);
	return 0;
}