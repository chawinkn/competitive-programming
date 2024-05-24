#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a[50009], b[50009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i-1];
	for (int i = 1; i <= n; i++) cin >> b[i], b[i] += b[i-1];
	for (int i = 2; i <= n; i++) a[i] = max(a[i], a[i-1]), b[i] = max(b[i], b[i-1]);
	while (q--) {
		ll k;
		cin >> k;
//		TLE
//		int ans=n;
//		for (ll x = 0; x <= k; x++) {
//			int i=lower_bound(a+1, a+n+1, x)-a;
//			int j=lower_bound(b+1, b+n+1, k-x)-b;
//			ans = min(ans, max(i, j));
//		}
//		cout << ans << "\n";
		int l=1, r=n;
		while (l < r) {
			int m=(l+r)/2;
			if (a[m] >= k-b[m]) r = m;
			else l = m+1;
		}
		cout << l << "\n";
//		OVERFLOW (c = a+b)
//		cout << lower_bound(c+1, c+n+1, k)-c << "\n";
	}
	return 0;
}