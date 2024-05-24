#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a[200009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, m, b, mx=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx += a[i];
	}
	sort(a, a+n);
	ll temp=a[n-1];
	for (int i = n-2, k = n; i >= 0; i--, k++) {
		temp += a[i];
		a[k] = temp;
	}	
	while (m--) {
		cin >> b;
		if (b > mx) cout << "NO\n";
		else if (b == 0) cout << "0\n";
		else {
			int idx=lower_bound(a, a+2*n, b)-a;
			if (idx >= n) cout << idx-n+2 << "\n";
			else cout << "1\n";
		}
	}
	return 0;
}
