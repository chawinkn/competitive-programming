#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll deg[100009], cnt[100009], ans[100009];
vector<pair<int,int>> g[100009];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
    	cin >> u >> v;
    	e.push_back({u, v});
    	g[u].push_back({v, i});
    	g[v].push_back({u, i});
    	deg[u]++, deg[v]++;
    	cnt[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 1) {
			deg[i] = 0;
			cnt[i] = 1;
			q.push(i);	
		}
	}
	while (!q.empty()) {
		int u=q.front(); q.pop();
		for (auto v : g[u]) {
			if (!deg[v]) continue;
			deg[v]--;
			cnt[v] += cnt[u];
			if (deg[v] == 1) q.push(v);
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}