#include <bits/stdc++.h>
using namespace std;

// Math

#define ll long long

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	ll ans, num;
	cin >> n >> num;
	ans = num;
	for (int i = 1; i < n; i++) {
		cin >> num;
		ans *= num/__gcd(ans, num);
	}
	cout << ans;
	return 0;
}