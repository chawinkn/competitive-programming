#include <bits/stdc++.h>
using namespace std;

vector<int> g[100009], level[100009];
int visited[100009], cnt=0;

void dfs(int u) {
	if (visited[u] == 1) {
		cnt = 2e9;
		return;
	}
	if (visited[u] == 2) return;
	visited[u] = 1;
	cnt++;
	for (auto v : g[u]) dfs(v);
	visited[u] = 2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, t;
	cin >> n >> k >> t;
	for (int i = 1; i <= n; i++) {
		int l, p;
		cin >> l >> p;
		level[l].push_back(i);
		while (p--) {
			int q;
			cin >> q;
			g[i].push_back(q);
		}
	}
	int ans=-1;
	for (int i = 1; i <= k; i++) {
		for (auto u : level[i]) dfs(u);
		if (cnt > t) break;
		ans = i;
	}
	cout << ans;
	return 0;
}