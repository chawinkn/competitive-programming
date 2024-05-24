#include <bits/stdc++.h>
using namespace std;

int parent[200009];
vector<tuple<int,int,int>> e;

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u]=find(parent[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, s, d, l;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	while (m--) {
		cin >> s >> d >> l;
		e.push_back({-(l-1), s, d});
	}
	sort(e.begin(), e.end());
	long long ans=0;
	for (auto [l, s, d] : e) {
		s=find(s), d=find(d);
		if (s == d) continue;
		parent[s] = d;
		ans -= l;
	}
	cout << ans;
	return 0;
}