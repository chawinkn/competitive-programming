#include <bits/stdc++.h>
using namespace std;

// Math + แชมป์นักจำ ?

// 80/100
// Official Solution N-ceil(sqrt(N))

#define ll long long

ll ans[100009];

void solve() {
	ll n;
	cin >> n;
	cout << ans[n] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	for (ll i = 3; i <= 100000; i++) {
		bool found=false;
		for (ll j = 1; j*j <= i; j++) {
			if (j*j == i) {
				ans[i] = i-j;
				found = true;
				break;
			}
		}
		if (found) continue;
		for (ll j = 1; j*j <= i-1; j++) {
			if (j*j == i-1) {
				ans[i] = i-j-1;
				found = true;
				break;
			}
		}
		if (found) continue;
		ans[i] = ans[i-1]+1;
	}
	while (q--) solve();
	return 0;
}