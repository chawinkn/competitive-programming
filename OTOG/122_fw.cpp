#include <bits/stdc++.h>
using namespace std;

int n, tree[200009];

void update(int i, int v) {
	for (; i <= n; i+=i&-i) tree[i] += v;
}

int query(int i) {
	int res=0;
	for (; i; i-=i&-i) res += tree[i];
	return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> n >> q;
	while (q--) {
		int a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update(b, d), update(c+1, -d);
		}
		else {
			cin >> b;
			cout << query(b) << "\n";
		}
	}
	return 0;
}