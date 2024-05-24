#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int M=1e9+7;
vector<int> g[500009];
ll factorial[500009], ways[500009];

void dfs(int u, int p) {
	int cnt=1;
	ways[u] = 1;
	for (auto v : g[u]) {
		if (v == p) continue;
		dfs(v, u);
		cnt++;
		ways[u] *= ways[v];
		ways[u] %= M;
	}
	ways[u] *= factorial[cnt-1];
	ways[u] %= M;
}

int main () {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, root, u, v;
	cin >> n >> u;
	root = u;
	for (int i = 0; i < 2*n-2; i++) {
		cin >> v;
		g[u].push_back(v);
		u = v;
	}
	factorial[0] = 1;
	for (int i = 1; i <= 500000; i++) {
		factorial[i] = factorial[i-1]*i;
		factorial[i] %= M;	
	}
	dfs(root, -1);
	cout << ways[root];
	return 0;
}