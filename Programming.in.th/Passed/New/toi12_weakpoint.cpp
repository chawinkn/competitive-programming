#include <bits/stdc++.h>
using namespace std;

vector<int> g[500009];
bool visited[500009];
int n, m, ans=0, idx;

int dfs(int u) {
	visited[u] = true;
	int cnt=1;
	bool cycle=false;
	for (auto v : g[u]) {
		if (v == m) cycle = true;
		if (visited[v]) continue;
		int res=dfs(v);
		cnt += res;
		if (res == 0) cycle = true;
	}
	if (cnt > ans) ans = cnt, idx = u;
	else if (cnt == ans) idx = min(idx, u);
	return (cycle ? 0 : cnt);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(m);
	cout << idx << "\n" << ans-1;
	return 0;
}