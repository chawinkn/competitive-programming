#include <bits/stdc++.h>
using namespace std;

int qs[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q, k;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> qs[i];
		qs[i] += qs[i-1];
	}
	for (int i = n-1; i >= 1; i--) qs[i] = min(qs[i], qs[i+1]);
	while (q--) {
		cin >> k;
		int ans=upper_bound(qs+1, qs+n+1, k)-qs-1;
		cout << ans << "\n";
	}
	return 0;
}