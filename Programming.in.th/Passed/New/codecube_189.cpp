#include <bits/stdc++.h>
using namespace std;

long long n, deg[100009], cnt[100009], ans[100009];
vector<pair<int,int>> g[100009];

//void dfs(int u, int p, int e) {
//	cnt[u] = 1;
//	for (auto [v,i] : g[u]) {
//		if (v == p || deg[v] != 0) continue;
//		dfs(v, u, i);
//		cnt[u] += cnt[v];
//	}
//	ans[e] = (n-cnt[u])*cnt[u];
//}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
    	cin >> u >> v;
    	g[u].push_back({v, i});
    	g[v].push_back({u, i});
    	deg[u]++, deg[v]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) cnt[i] = 1;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 1) q.push(i);	
	}
	while (!q.empty()) {
		int u=q.front(); q.pop();
		for (auto [v,i] : g[u]) {
			if (deg[v] != 0) continue;
			cnt[v] += cnt[u];
			ans[i] = (n-cnt[u])*cnt[u];
			deg[u]--, deg[v]--;
			if (deg[v] == 1) q.push(v);
		}
	}
//	for (int i = 1; i <= n; i++) {
//		if (deg[i] == 2) dfs(i, 0, 0);
//	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}