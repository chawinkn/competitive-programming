#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int x, y, a, b;
	ll ans=0;
	cin >> x >> y >> a >> b;
	while (x > 1) {
		if (x%y == 0) {
			int X=x;
			x /= y;
			ans += min(b, (X-x)*a);
		}
		else {
			x--;
			ans += a;
		}
	}
	cout << ans;
	return 0;
}