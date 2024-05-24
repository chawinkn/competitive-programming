#include <bits/stdc++.h>
using namespace std;

int qs[100009];

int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> qs[i], qs[i] += qs[i-1];
	for (int i = 2; i <= n; i++) qs[i] = max(qs[i], qs[i-1]);
	while (q--) {
		int x;
		cin >> x;
		int idx=lower_bound(qs+1, qs+n+1, x)-qs-1;
		cout << (idx != n ? idx : -1) << "\n";
	}
	return 0;
}