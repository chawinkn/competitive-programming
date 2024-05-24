#include <bits/stdc++.h>
using namespace std;

int U[109];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	int l=0, r=0;
	for (int i = 1; i <= n; i++) {
		cin >> U[i];	
		l = max(l, U[i]);
		r += U[i];
	}
	while (l < r) {
		int mid=(l+r)/2, sum=0, cnt=1;
		for (int i = 1; i <= n; i++) {
			sum += U[i];
			if (sum > mid) {
				sum = U[i];
				cnt++;
			}
		}
		if (cnt <= m) r = mid;
		else l = mid+1;
	}
	cout << l;
	return 0;
}