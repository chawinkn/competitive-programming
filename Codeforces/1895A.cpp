#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long t, x, y, k;
	cin >> t;
	while (t--) {
		int ans;
		cin >> x >> y >> k;
		if (x < y) { // chest
			if (y <= x+k) cout << y << "\n";
			else cout << 2*y-(x+k) << "\n";
		}
		else { // key
			cout << x << "\n";
		}
	}
	return 0;
}