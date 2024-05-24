#include <bits/stdc++.h>
using namespace std;

vector<int> g[50009];
int k, ans=0, total=0, P[50009];

int dfs(int u, int p) {
	int sum=0;
	for (auto v : g[u]) {
		if (v == p) continue;
		int res=dfs(v, u)+P[v];
		if (abs((total-res)-res) <= k) ans++;
		sum += res;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> P[i], total += P[i];
	for (int i = 1; i <= n-1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);
	cout << ans;
	return 0;
}