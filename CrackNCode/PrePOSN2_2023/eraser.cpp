#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> C(39, 1e18);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n; int k;
    cin >> n >> k >> C[0];
    for (int i = 1; i <= k; i++) {
    	int p; ll c;
    	cin >> p >> c;
    	C[p] = min(C[p], c);
	}
	for (int i = 1; i <= 31; i++) {
		C[i] = min(C[i], 2*C[i-1]);
	}
	ll ans=0;
	for (int i = 31; i >= 0 && n > 0; i--) {
		ll amt=(1ll<<i);
		if (n >= amt) {
			n -= amt;
			ans += C[i];
		}
	}
	cout << ans;
 	return 0;   
}