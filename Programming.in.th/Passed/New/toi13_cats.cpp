#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll c[2000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n;
	cin >> n;
	ll l=0, r=0;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		r = max(r, c[i]);	
	}
	while (l < r) {
		ll m=(l+r)>>1, valid=1;
		stack<ll> st;
		for (int i = 1; i <= n; i++) {
			if (m >= c[i]) continue;
			if (st.empty()) st.push(c[i]);
			else {
				if (c[i] == st.top()) st.pop();
				else {
					valid = 0;
					break;
				}
			}
		}
		if (valid) r = m;
		else l = m+1;
	}
	cout << l;
	return 0;
}