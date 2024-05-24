#include <bits/stdc++.h>
using namespace std;

#define ll long long

// 44/100

int d[100009], dist[100009];
bool visited[100009];
vector<int> g[100009], tt[100009];
queue<int> Q;
priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, s, q;
	cin >> n >> m >> s >> q;
	for (int i = 1; i <= n; i++) cin >> d[i];
	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dist[s] = 0;
	visited[s] = true;
	tt[0].push_back(s);
	Q.push(s);
	int mxt=0;
	while (!Q.empty()) {
		auto u=Q.front(); Q.pop();
		for (auto v : g[u]) {
			if (visited[v]) continue;
			visited[v] = true;
			dist[v] = dist[u]+1;
			mxt = max(mxt, dist[v]);
			tt[dist[v]].push_back(v);
			Q.push(v);
		}
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			tt[dist[x]+1].push_back(0), d[0] = y;
			ll ans=0;
			while (!pq.empty()) pq.pop();
			for (int i = max(mxt, dist[x]+1); i >= 1; i--) {
				for (auto j : tt[i]) pq.push(d[j]);
				ans += pq.top();
				pq.pop();
			}
			cout << ans << "\n";
			tt[dist[x]+1].pop_back(), d[0] = 0;
		}
		else {
			int y;
			cin >> y;
			ll ans=0;
			for (int x = 1; x <= n; x++) {
				tt[dist[x]+1].push_back(0), d[0] = y;
				ll total=0;
				while (!pq.empty()) pq.pop();
				for (int i = max(mxt, dist[x]+1); i >= 1; i--) {
					for (auto j : tt[i]) pq.push(d[j]);
					total += pq.top();
					pq.pop();
				}
				ans += total;
				tt[dist[x]+1].pop_back(), d[0] = 0;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}