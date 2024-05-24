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
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(c, b);
		else cout << query(c)-query(b-1) << "\n";
	}
	return 0;
}