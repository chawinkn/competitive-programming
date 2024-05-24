#include <bits/stdc++.h>
using namespace std;

int a[500009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, b;
	cin >> n >> b;
	int l=1, r=1;
	for (int i = 1; i <= n; i++) cin >> a[i], r = max(r, a[i]);
	while (l < r) {
		int m=(l+r)/2, cnt=0;
		for (int i = 1; i <= n; i++) cnt += a[i]/m+(a[i]%m != 0);
		if (cnt <= b) r = m;
		else l = m+1;
	}
	cout << l;
	return 0;
}