#include <bits/stdc++.h>
using namespace std;

int x[30001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, d, ans=0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) {
		d = upper_bound(x, x+n, x[i]+k)-x-i-1;
		ans = max(ans, d);
	}
	cout << ans;
	return 0;
}
