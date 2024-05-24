#include <bits/stdc++.h>
using namespace std;

int parent[3009];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

int main() {
   	ios_base::sync_with_stdio(false); cin.tie(NULL);
   	int n, m;
   	cin >> n >> m;
   	for (int i = 0; i < n; i++) parent[i] = i;
	vector<tuple<int,int,int>> e(m);
   	for (auto& [l,u,v] : e) {
   		int r;
   		cin >> u >> v >> l >> r;
   		if (r) parent[find(u)] = find(v);
	}
	int p;
	cin >> p;
	vector<pair<int,int>> packet(p);
	for (auto& [d,c] : packet) cin >> d >> c;
	sort(packet.begin(), packet.end());
	for (int i = p-2; i >= 0; i--) {
		packet[i].second = min(packet[i].second, packet[i+1].second);
	}
	for (auto& [l,u,v] : e) {
		l = packet[lower_bound(packet.begin(), packet.end(), make_pair(l,0))-packet.begin()].second;
	}
	sort(e.begin(), e.end());
	int ans=0;
	for (auto [l,u,v] : e) {
		u=find(u), v=find(v);
		if (u == v) continue;
		parent[u] = v;
		ans += l;
	}
	cout << ans;
   	return 0;
}