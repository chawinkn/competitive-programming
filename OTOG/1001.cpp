#include <bits/stdc++.h>
using namespace std;

int n, m, tree[200009];

void update(int i, int v) {
	for (; i <= m; i+=i&-i) tree[i] += v;
}

int query(int i) {
	int res=0;
	for (; i; i-=i&-i) res += tree[i];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r;
			cin >> l >> r;
			update(l, 1), update(r+1, -1);
		}
		else {
			int x;
			cin >> x;
			cout << query(x) << "\n";
		}
	}
	for (int i = 1; i <= m; i++) cout << query(i) << " ";
	return 0;
}