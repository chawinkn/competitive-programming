#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<tuple<ll,ll,int,int>> package;
int parent[100009];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u]=find(parent[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	ll b;
	cin >> n >> m >> b;
	while (m--) {
		int u, v, p, c;
		cin >> u >> v >> p >> c;
		package.push_back({p, c, u, v});
	}
	int l=0, r=1e8;
	while (l < r) {
		int mid=l+(r-l+1)/2;
		vector<tuple<ll,int,int>> e;
		for (auto [p,c,u,v] : package) e.push_back({mid*p+c, u, v});
		sort(e.begin(), e.end());
		for (int i = 1; i <= n; i++) parent[i] = i;
		ll cost=0;
		for (auto [w,u,v] : e) {
			u = find(u), v = find(v);
			if (u == v) continue;
			parent[u] = v;
			cost += w;
		}
		if (cost <= b) l = mid;
		else r = mid-1;
	}
	cout << l;
	return 0;
}