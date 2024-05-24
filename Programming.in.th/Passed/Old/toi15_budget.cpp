#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<pair<int,pair<int,int>>> g;
vector<pair<int,int>> arr;
vector<int> temp;
int parent[3007];

int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u != v) parent[u] = v;
}

int main() {
	int b, e, u, v, l, r, p, c, d, ans=0;
	cin >> b >> e;
	for (int i = 0; i < e; i++) {
		cin >> u >> v >> l >> r;
		if (r) l = 0;
		g.push_back({l, {u, v}});	
	}
	cin >> p;
	for (int i = 0; i < p; i++) {
		cin >> d >> c;	
		arr.push_back({c, d});
	}
	
	sort(g.begin(), g.end());
	for (int i = 0; i < b; i++) parent[i] = i;
	for (auto i : g) {
		l = i.f, u = i.s.f, v = i.s.s;
		if (find(u) == find(v)) continue;
		merge(u, v);
		if (l != 0) temp.push_back(l);
	}
	sort(arr.begin(), arr.end());
	for (auto i : temp) {
		for (auto j : arr) {
			if (j.s >= i) {
				ans += j.f;
				break;
			}
		}
	}
	cout << ans;	
	return 0;
}
