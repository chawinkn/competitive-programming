#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> g[200009], visited(200009);
char c[200009];
priority_queue<ll> pq[29];
queue<pair<int,ll>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k, u, v;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> c[i];
	while (m--) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	q.push({1, 0});
	pq[c[1]-'A'].push(0);
	visited[1] = true;
	while (!q.empty()) {
		auto [u,d]=q.front(); q.pop();
		for (auto v : g[u]) {
			if (visited[v]) continue;
			visited[v] = true;
			pq[c[v]-'A'].push(-(d+1));
			q.push({v, d+1});
		}
	}
	ll ans=0;
	for (int i = 1; i <= k; i++) {
		char t;
		cin >> t;	
		if (pq[t-'A'].empty()) {
			cout << -1;
			return 0;
		}
		ans -= pq[t-'A'].top(), pq[t-'A'].pop();
	}
	cout << 2*ans;
	return 0;
}