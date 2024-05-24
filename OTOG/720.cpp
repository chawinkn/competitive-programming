#include <bits/stdc++.h>
using namespace std;

#define ll long long

int tt[50009], p[50009], t[50009];
string pp[50009];
vector<pair<int,int>> g[50009];
map<string,int> mp;
priority_queue<pair<ll,int>> pq;

int main() {
	int n, m;
	ll mxfuel;
	char a[109], b[109];
	scanf("%d %d %s %s %lld", &n, &m, a, b, &mxfuel);
	for (int i = 1; i <= n; i++) {
		cin >> pp[i] >> tt[i];
		mp[pp[i]] = 0;
	}
	int idx=0;
	for (auto &i : mp) i.second = idx++;
	vector<int> T;
	for (int i = 1; i <= n; i++) t[mp[pp[i]]] = tt[i], T.push_back(tt[i]);
	sort(T.begin(), T.end());
	while (m--) {
		char u[109], v[109];
		int w;
		scanf("%s %s %d", u, v, &w);
		g[mp[u]].push_back({mp[v], w});
		g[mp[v]].push_back({mp[u], w});
	}
	ll ans=1e18;
	int l=0, r=idx-1;
	while (l < r) {
		int mid=(l+r)/2;
		vector<ll> dist(idx, 1e18);
		vector<bool> visited(idx);
		dist[mp[a]] = 0;
		pq.push({0, mp[a]});
		while (!pq.empty()) {
			auto [d,u]=pq.top(); pq.pop();
			if (visited[u]) continue;
			visited[u] = true;
			for (auto [v,w] : g[u]) {
				if (t[v] <= T[mid] && dist[u]+w < dist[v]) {
					dist[v] = dist[u]+w;
					pq.push({-dist[v], v});
				}
			}
		}
		if (dist[mp[b]] <= mxfuel) r = mid, ans = dist[mp[b]]; 
		else l = mid+1;
	}
	printf("%d %lld", T[l], ans);
	return 0;
}