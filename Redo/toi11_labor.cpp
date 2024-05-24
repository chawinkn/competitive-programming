#include <bits/stdc++.h>
using namespace std;

#define ll long long

int t[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m;
	ll n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) cin >> t[i];
	ll l=1, r=1e12;
	while (l < r) {
		ll mid=(l+r)>>1LL, sum=0;
		for (int i = 1; i <= m; i++) sum += mid/t[i];
		if (sum >= n) r = mid;
		else l = mid+1;
	}
	cout << l;
	return 0;
}