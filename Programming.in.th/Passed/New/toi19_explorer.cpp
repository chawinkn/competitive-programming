#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M=1e9+7;

vector<int> g[500009];
ll ans[500009], fac[500009];

int dfs(int u, int p) {
	int cnt=1;
	ans[u] = 1;
	for (auto v : g[u]) {
		if (v == p) continue;
		ans[u] *= dfs(v, u), ans[u] %= M;
		cnt++;
	}
	ans[u] *= fac[cnt-1], ans[u] %= M;
	return ans[u];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, root;
	cin >> n >> root;
	int u=root;
	for (int i = 2; i <= 2*n-1; i++) {
		int v;
		cin >> v;
		g[u].push_back(v);
		u = v;
	}
	fac[0] = 1;
	for (int i = 1; i <= 500000; i++) fac[i] = i*fac[i-1], fac[i] %= M;
	dfs(root, root);
	cout << ans[root];
	return 0;
}