#include <bits/stdc++.h>
using namespace std;

vector<int> g[500009];
int n, m, idx, ans;
bool visited[500009];

int dfs(int u) {
	visited[u] = true;
	int cnt=1;
	bool cycle=false;
	for (auto v : g[u]) {
		if (v == m) cycle = true;
		if (visited[v]) continue;
		int res=dfs(v);
		if (res == 0) cycle = true;
		cnt += res;
	}
	if (cnt > ans) {
		ans = cnt;
		idx = u;
	}
	else if (cnt == ans) idx = min(idx, u);
	if (cycle) return 0;
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	idx=n+1, ans=0;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(m);
	cout << idx << "\n" << ans-1;
	return 0;
}