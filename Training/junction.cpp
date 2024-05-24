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
	int l=2e4, r=0;
	for (int i = 1; i <= n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		l = min(l, w), r += w;
		g[u].push_back({w, v});
		g[v].push_back({w, u});
	}
	for (int i = 0; i <= n; i++) sort(g[i].begin(), g[i].end());
	for (int i = 0; i <= n; i++) {
		if (g[i].size() == 1) {
			dfs(i, i);
			break;
		}
	}
	while (l < r) {
		int mid=l+(r-l+1)/2;
		int sum=0, cnt=0;
		for (auto w : dist) {
			sum += w;
			if (sum >= mid) {
				sum = 0;
				cnt++;
			}
		}
		if (cnt < 3) r = mid-1;
		else l = mid;
	}
	cout << l;
	return 0;
}