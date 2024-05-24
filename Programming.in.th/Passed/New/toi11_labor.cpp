#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll t[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll m, n, mx=0;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		cin >> t[i];
		mx = max(mx, t[i]);	
	}
	ll l=1, r=mx*n;
	while (l < r) {
		ll mid=(l+r)>>1, sum=0;
		for (int i = 1; i <= m; i++) sum += mid/t[i];
		if (sum >= n) r = mid;
		else l = mid+1;
	}
	cout << l;
	return 0;
}