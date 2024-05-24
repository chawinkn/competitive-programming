#include <bits/stdc++.h>
using namespace std;

// Math

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, ans;
	cin >> n >> ans;
	for (int i = 0; i < n-1; i++) {
		int num;
		cin >> num;
		ans = __gcd(ans, num);
	}
	cout << ans;
	return 0;
}