#include <bits/stdc++.h>
using namespace std;

// Binary Search

#define ll long long

ll t[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m;
	ll n, l=1, r=0;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		cin >> t[i];
		r = max(r, t[i]);
	}
	r *= n;
	while (l < r) {
		ll mid=(l+r)/2, cnt=0;
		for (int i = 1; i <= m; i++) cnt += mid/t[i];
		if (cnt >= n) r = mid;
		else l = mid+1;
	}
	cout << l;
	return 0;
}