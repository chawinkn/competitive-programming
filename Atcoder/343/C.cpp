#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, ans=1;
	cin >> n;
	for (ll i = 1; i*i*i <= 1e18; i++) {
		ll num=i*i*i, now=i*i*i, v=0;
		while (num) {
			v = v*10+num%10;
			num /= 10;
		}
		if (v == now && now <= n) ans = max(ans, now);
	}
	cout << ans;
	return 0;
}