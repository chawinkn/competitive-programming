#include <bits/stdc++.h>
using namespace std;

int a[109];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int k, n;
	cin >> k >> n;
	int l=0, r=0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		l = max(l, a[i]);
		r += a[i];
	}
	while (l < r) {
		int m=(l+r)/2;
		int sum=0, cnt=1;
		for (int i = 1; i <= n; i++) {
			sum += a[i];
			if (sum > m) {
				sum = a[i];
				cnt++;
			}
		}
		if (cnt <= k) r = m;
		else l = m+1;
	}
	cout << l;
	return 0;
}