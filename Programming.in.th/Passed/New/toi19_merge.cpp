#include <bits/stdc++.h>
using namespace std;

int x[100009], y[100009], s[100009], t[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i-1];
	for (int i = 1; i <= m; i++) cin >> y[i];
	for (int i = 1; i <= m; i++) cin >> t[i], t[i] += t[i-1];
	while (q--) {
		int a, b, k;
		cin >> a >> b >> k;
		int l=-1e9, r=1e9;
		while (l < r) {
			int mid=l+(r-l)/2;
			int cntx=s[upper_bound(x+1, x+n+1, mid)-x-1];
			int cnty=t[upper_bound(y+1, y+m+1, (mid-b)/a)-y-1];
			if (cntx+cnty >= k) r = mid;
			else l = mid+1;
		}
		cout << l << "\n";
	}
	return 0;
}