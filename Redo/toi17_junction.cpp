#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[80009];
vector<int> dist;

void dfs(int u, int p) {
	for (auto [w,v] : g[u]) {
		if (v == p) continue;
		dist.push_back(w);
		dfs(v, u);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int l=1, r=0;
	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		r += w;
		g[u].push_back({w, v});
		g[v].push_back({w, u});
	}
	for (int i = 0; i <= n; i++) sort(g[i].begin(), g[i].end());
	for (int i = 0; i <= n; i++) {
		if (g[i].size() == 1) {
			dfs(i, -1);
			break;
		}
	}
	while (l < r) {
		int m=l+(r-l+1)/2, cnt=0, sum=0;
		for (auto i : dist) {
			sum += i;
			if (sum >= m) {
				sum = 0;
				cnt++;
			}
		}
		if (cnt >= 3) l = m;
		else r = m-1;
	}
	cout << l;
	return 0;
}