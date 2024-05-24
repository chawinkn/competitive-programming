#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, t;
	cin >> n >> t;
	vector<ll> k(n);
	ll l=0, r=1e18;
	for (int i = 0; i < n; i++) cin >> k[i];	
	while (l < r) {
		ll m=(l+r)/2, cnt=0;
		for (auto i : k) {
			cnt += m/i;
			if (cnt >= t) break;	
		}
		if (cnt >= t) r = m;
		else l = m+1;
	}
	cout << l;
	return 0;
}
