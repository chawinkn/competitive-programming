#include <bits/stdc++.h>
using namespace std;

int arr[1000001], ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k, l, p, ml, ul, ur;
	cin >> n >> m >> k >> l;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < k; i++) {
		ans = 0;
		ml = 0;
		for (int j = 0; j < m; j++) {
			cin >> p;
			ul = lower_bound(arr+ml, arr+n, max(0, p-l))-arr;
			ur = upper_bound(arr+ml, arr+n, min(9999999, p+l))-arr;
			ml = max(ml, ur);
			ans += ur-ul;
		}
		cout << ans << "\n";
	}
	return 0;
}
