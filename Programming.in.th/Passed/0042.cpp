#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	long double n, ans;
	cin >> q;
	while (q--) {
		cin >> n;
		ans = pow(2, n);
		cout << fixed << setprecision(0) << ans << "\n";
	}
	return 0;
}
