#include <bits/stdc++.h>
using namespace std;

int parent[3009];
vector<tuple<int,int,int>> e;
vector<pair<int,int>> pro;
vector<int> temp;

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u]=find(parent[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int b, m, s, t, l, r, p, c, d;
	cin >> b >> m;
	for (int i = 0; i < b; i++) parent[i] = i;
	while (m--) {
		cin >> s >> t >> l >> r;
		if (r) parent[find(s)] = find(t);
		e.push_back({l, s, t});
	}
	cin >> p;
	for (int i = 0; i < p; i++) {
		cin >> d >> c;
		pro.push_back({d, c});
	}
	sort(e.begin(), e.end());
	sort(pro.begin(), pro.end());
	for (int i = p-2; i >= 0; i--) pro[i].second = min(pro[i].second, pro[i+1].second);
	int ans=0;
	for (auto [l,s,t] : e) {
		s=find(s), t=find(t);
		if (s == t) continue;
		parent[s] = t;
		int idx=lower_bound(pro.begin(), pro.end(), make_pair(l,0))-pro.begin();
		ans += pro[idx].second;
	}
	cout << ans;
	return 0;
}