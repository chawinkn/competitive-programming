#include <bits/stdc++.h>
using namespace std;

#define ll long long

int p[100009];

int find(int u) {
	if (u == p[u]) return u;
	return p[u] = find(p[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) p[i] = i;
	vector<tuple<ll,int,int>> e;
	while (m--) {
		int a, b; ll w;
		cin >> a >> b >> w;
		e.push_back({w, a, b});
	}
	sort(e.begin(), e.end()); reverse(e.begin(), e.end());
	int cnt=n;
	for (auto [w,u,v] : e) {
		u = find(u), v = find(v);
		if (u == v) continue;
		p[u] = v;
		cnt--;
//		set<int> s;
//		for (int i = 1; i <= n; i++) s.insert(find(i));
		if (cnt == k) {
			cout << w;
			break;
		}
	}
	return 0;
}