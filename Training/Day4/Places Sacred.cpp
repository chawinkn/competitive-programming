#include <bits/stdc++.h>
using namespace std;

// MST

#define ll long long

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
		int s, d, l;
		cin >> s >> d >> l;
		E.emplace_back(-(l-1), s, d);
	}
	iota(p+1, p+n+1, 1);
	sort(E.begin(), E.end());
	ll ans=0;
	for (auto i : E) {
		int w, u, v;
		tie(w, u, v) = i;
		u = find(u), v = find(v);
		if (u == v) continue;
		p[u] = v;
		ans -= w;
	}
	cout << ans;
	return 0;
}