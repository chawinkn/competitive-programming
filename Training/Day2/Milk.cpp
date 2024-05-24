#include <bits/stdc++.h>
using namespace std;

// DSU

int p[100009];

int find(int u) {
	if (u == p[u]) return u;
	return p[u]=find(p[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) p[i] = i;
	while (q--) {
		int x, y;
		char t;
		cin >> t >> x >> y;
		x = find(x), y = find(y);
		if (t == 'c') {
			if (x == y) continue;
			p[x] = y;
		}
		else cout << (x == y ? "yes" : "no") << "\n";
	}
	return 0;
}