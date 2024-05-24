#include <bits/stdc++.h>
using namespace std;

int tree[100009];

void update(int i, int v) {
	for (; i <= 100000; i+=i&-i) {
		tree[i] += v;
	}
}

int query(int i) {
	int ans=0;
	for (; i; i-=i&-i) {
		ans += tree[i];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;
		cout << query(h) << " ";
		update(h, 1);
	}
	return 0;
}