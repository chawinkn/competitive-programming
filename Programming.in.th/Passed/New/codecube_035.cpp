#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long

ll arr[100009], visited[100009];
vector<ll> g[100009], tt[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, m, k, u, v, mt=0, ans=0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	while (m--) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue<pair<int,int>> q;
	q.push({k, 0});
	while (!q.empty()) {
		ll u=q.front().f, t=q.front().s; q.pop();
		if (visited[u]) continue;
		
		visited[u] = 1;
		mt = max(mt, t);
		tt[t].push_back(arr[u]);
		for (auto i : g[u]) q.push({i, t+1});
	}
	priority_queue<int> pq;
	for (int i = mt; i >= 1; i--) {
		for (auto j : tt[i]) pq.push(j);
		if (pq.top() < 0) continue;
		ans += pq.top(); 
		pq.pop();
	}
	for (int i = 1; i <= n; i++) {
		if (!g[i].size() && arr[i] >= 0) ans += arr[i];
	}
	cout << ans;
	return 0;
}
