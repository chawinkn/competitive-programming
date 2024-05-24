#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, M;
	cin >> n >> M;
	vector<ll> a(n);
	for (auto& i : a) cin >> i;
	sort(a.begin(), a.end());
	vector<ll> qs(n);
	qs[0] = a[0];
	for (int i = 1; i < n; i++) qs[i] = qs[i-1]+a[i];
	if (M == 1) {
		int m=n/2;
		cout << (a[m]*(m+1)-qs[m])+(qs[n-1]-qs[m]-a[m]*(n-m-1));
	}
	else {
		ll ans=1e18;
		// [0..i] [i+1..n-1]
		for (int i = 0; i < n; i++) {
			int m1=min(n-1,(i+1)/2), m2=min(n-1,i+1+(n-i-1)/2);
			ll l=(a[m1]*(m1+1)-qs[m1])+(qs[i]-qs[m1]-a[m1]*(i-m1));
			ll r=(a[m2]*(m2-i)-(qs[m2]-qs[i]))+(qs[n-1]-qs[m2]-a[m2]*(n-m2-1));
			ans = min(ans, l+r);
		}
		cout << ans;
	}
    return 0;
}