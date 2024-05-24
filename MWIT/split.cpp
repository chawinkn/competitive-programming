#include <bits/stdc++.h>
using namespace std;

#define ll long long

// 41/100

ll a[300009], s[300009], qs[300009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		qs[i] = qs[i-1]+a[i];
		s[i] = s[i-1]+a[i]*i;
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		ll ans=1e18;
		// [l,i] [i+1,r]
		for (int i = l; i < r; i++) {
			ll left=s[i]-s[l-1]-(l-1)*(qs[i]-qs[l-1]), right=s[r]-s[i]-(i)*(qs[r]-qs[i]);
			ans = min(ans, abs(left-right));
		}
		cout << ans << "\n";
	}
	// for (int l = 1; l <= n; l++) {
	// 	for (int r = l; r <= n; r++) {
	// 		ll sum=0;
	// 		for (int k = l; k <= r; k++) sum += a[k]*(k-l+1);
	// 		cout << l << " " << r << " = " << sum << " , " << s[r]-s[l-1]-(l-1)*(qs[r]-qs[l-1]) << "\n";
	// 	}
	// }
	return 0;
}