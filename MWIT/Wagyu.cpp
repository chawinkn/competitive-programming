#include <bits/stdc++.h>
using namespace std;

int a[100009], valid[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int r=1, sum=0;
	for (int l = 1; l <= n; l++) {
		while (r <= n && sum < m) sum += a[r++];
		if (sum == m) valid[l] = r-1;
		else valid[l] = n+1;
		sum -= a[l];
	}
	for (int i = n-1; i >= 1; i--) valid[i] = min(valid[i], valid[i+1]);
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << (valid[l] <= r ? "Yes" : "No") << "\n";
	}
	return 0;
}