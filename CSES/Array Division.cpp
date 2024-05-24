#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	vector<ll> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	ll l=0, r=1e18;
	while (l < r) {
		ll m=(l+r)/2, sum=0, cnt=1;
		for (auto i : x) {
			if (i > m) {
				cnt = 1e6;
				break;
			}
			sum += i;
			if (sum > m) {
				sum = i;
				cnt++;
			}
		}
		cout << m << " " << cnt << "\n";
		if (cnt <= k) r = m;
		else l = m+1;
	}
	cout << l;
	return 0;
}