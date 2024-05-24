#include <bits/stdc++.h>
using namespace std;

int a[1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int l=0, r=2e6;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		l = max(l, a[i]);	
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