#include <bits/stdc++.h>
using namespace std;

int a[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, p;
	cin >> n >> k >> p;
	int l=1e6, r=1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		l = min(l, a[i]);
		r = max(r, a[i]);
	}
	while (l < r) {
		int m=(l+r)/2, cnt=0; // count jump
		for (int i = 1; i <= n; ) {
			if (a[i] > m) {
				i += p;
				cnt++;
			}
			else i++;
		}
		if (cnt <= k) r = m;
		else l = m+1;
	}
	cout << l;
	return 0;
}