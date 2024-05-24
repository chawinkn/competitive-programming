#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, mx=-2e9, mn=2e9;
	cin >> n;
	while (n--) {
		cin >> k;
		mx = max(mx, k);
		mn = min(mn, k);
	}
	cout << mx << "\n" << mn;
	return 0;
}