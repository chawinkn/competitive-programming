#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y, a, b, ans=0;
	cin >> x >> y >> a >> b;
	while (1) {
		if (x == 1) break;
		if (x%y == 0 && b <= a) {
			x /= y;
			ans += b;
		}
		else {
			x--;
			ans += a;
		}
	}
	cout << ans;
	return 0;
}
