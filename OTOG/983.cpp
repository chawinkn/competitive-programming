#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a[10009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	ll L=0, R=0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		L = min(L, a[i]);
		R += a[i];	
	}
	while (q--) {
		int k;
		cin >> k;
		ll l=L, r=R;
		while (l < r) {
			ll m=(l+r)/2, sum=0;
			int cnt=0;
			for (int i = 1; i <= n; i++) {
				sum += a[i];
				if (sum >= m) {
					sum = 0;
					cnt++;
				}
			}
			if (sum != 0 && sum < m) cnt++;
			if (cnt <= k) r = m;
			else l = m+1;
		}
		cout << l << "\n";
	}
	return 0;
}