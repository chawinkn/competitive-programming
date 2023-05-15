#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int p[100003], parent[100003];
vector<pair<int,pair<int,int>>> g;

int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		parent[i] = i;	
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		int t=p[a]+p[b];
		g.push_back({t, {a, b}});
	}
	sort(g.begin(), g.end());
	int ans=0;
	for (auto i : g) {
		int t=i.f, u=i.s.f, v=i.s.s;
		if (find(u) == find(v)) continue;
		parent[u] = v;
		ans += t;
	}
	cout << ans;
	return 0;
}
