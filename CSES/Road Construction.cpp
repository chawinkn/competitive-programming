#include <bits/stdc++.h>
using namespace std;

int sz[100009], parent[100009];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
	int cnt=n, mx=1;
	while (m--) {
		cin >> a >> b;
		a=find(a), b=find(b);
		if (a != b) {
			cnt--;
			if (sz[a] > sz[b]) {
				sz[a] += sz[b];
				parent[b] = a;
				mx = max(mx, sz[a]);
			}
			else {
				sz[b] += sz[a];
				parent[a] = b;
				mx = max(mx, sz[b]);
			}
		}
		cout << cnt << " " << mx << "\n";
	}
	return 0;
}