#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;
vector<pair<int,int>> g[100003];
pair<int,int> arr[100003];

// 9/100 points

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k, q, t, u, v, p, l, r, s, e, a;
	cin >> n >> m >> k >> q;
	for (int i = 1; i <= k; i++) {
		cin >> a;
		if (mp.find(a) == mp.end()) mp[a] = 1;
		else mp[a]++;
	}
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
		arr[i] = {-1, -1};
	}
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> p >> l >> r;
			arr[p] = {l, r};
		}
		else {
			cin >> s >> e;
			int ans=0;
			for (auto i : mp) {
				vector<bool> visited(n+1, false);
				queue<int> q;
				q.push(s);
				visited[s] = true;
				while (!q.empty()) {
					u = q.front(); 
					q.pop();
					if (u == e) {
						ans++;
						break;
					}
					for (auto j : g[u]) {
						if (visited[j.first]) continue;
						if (i.second >= arr[j.second].first && i.second <= arr[j.second].second) continue;
						visited[j.first] = true;
						q.push(j.first);
					}
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
