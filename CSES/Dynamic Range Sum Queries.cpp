#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, q, x[200009];
ll tree[200009];

void update(int i, int v) {
	int diff = v-x[i];
	x[i] = v;
	for (; i <= n; i+=i&-i) tree[i] += diff; 
}

ll query(int i) {
	ll res=0;
	for (; i; i-=i&-i) res += tree[i];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> x[0];
		update(i, x[0]);
	}
	while (q--) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 1) update(a, b);
		else cout << query(b)-query(a-1) << "\n";
	}
	return 0;
}