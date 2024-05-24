#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, o, l=0, r=0;
	cin >> m >> o;
	vector<int> a(o);
	for (int i = 0; i < o; i++) {
		cin >> a[i];
		l = max(l, a[i]);
		r += a[i];
	}
	while (l < r) {
		int mid=(l+r)>>1, sum=0, cnt=1;
		for (int i = 0; i < o; i++) {
			sum += a[i];
			if (sum > mid) sum = a[i], cnt++;
		}
		if (cnt <= m) r = mid;
		else l = mid+1;
	}
	cout << l;
	return 0;
}