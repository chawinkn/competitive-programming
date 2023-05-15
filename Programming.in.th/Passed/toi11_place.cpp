#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int parent[200003];
vector<pair<int,pair<int,int>>> g;

int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

int main() {
	int n, m, s, d, l;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &s, &d, &l);
		g.push_back({-(l-1), {s, d}});
	}
	for (int i = 1; i <= n; i++) parent[i] = i;
	sort(g.begin(), g.end());
	long long int ans=0;
	for (auto i : g) {
		int d=-i.f, u=i.s.f, v=i.s.s;
		if (find(u) == find(v)) continue;
		parent[u] = v;
		ans += d;
	}
	cout << ans;
	return 0;
}
