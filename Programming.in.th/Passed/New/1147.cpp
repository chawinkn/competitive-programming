#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 262144;
int n, q, tree[2*MAX_N];

int query(int l, int r) {
	l += n, r += n;
	int mx=-1e9;
	while (l <= r) {
		if (l%2 == 1) mx = max(mx, tree[l++]);
		if (r%2 == 0) mx = max(mx, tree[r--]);
		l /= 2, r /= 2;
	}
	return mx;
}

void update(int l, int v) {
	l += n;
	tree[l] = v;
	for (l /= 2; l >= 1; l /= 2) {
		tree[l] = max(tree[2*l], tree[2*l+1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> q;
	while (q--) {
		int i, z, a, b;
		char t;
		cin >> t;
		if (t == 'U') {
			cin >> i >> z;
			update(i-1, z);
		}
		else if (t == 'P') {
			cin >> a >> b;
			cout << query(a-1, b-1) << "\n";
		}
	}
	return 0;
}