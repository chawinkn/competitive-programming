#include <bits/stdc++.h>
using namespace std;

// Quicksum 2D

void solve() {
	int m, n, t;
	cin >> m >> n >> t;
	vector<vector<int>> tree(m+1, vector<int>(n+1));
	while (t--) {
		int r, c;
		cin >> r >> c; r++, c++;
		tree[r][c] = 1;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			tree[i][j] += tree[i-1][j]+tree[i][j-1]-tree[i-1][j-1];
		}
	}
	for (int k = min(m, n); k >= 3; k--) {
		for (int i = k; i <= m; i++) {
			for (int j = k; j <= n; j++) {
				int all=tree[i][j]-tree[i][j-k]-tree[i-k][j]+tree[i-k][j-k];
				int in=tree[i-1][j-1]-tree[i-1][j-k+1]-tree[i-k+1][j-1]+tree[i-k+1][j-k+1];
				if (all-in != 0) continue;
				cout << k << "\n";
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q=2;
	while (q--) solve();
	return 0;
}