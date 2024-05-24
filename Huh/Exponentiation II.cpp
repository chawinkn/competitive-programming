#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int M=1e9+7;

// a*b mod m = (a mod m * b mod m) mod m

ll expo(ll a, ll b, ll MOD) {
	if (b == 0) return 1;
	if (b == 1) return a % MOD;
	ll c=expo(a, b/2, MOD);
	if (b%2 == 0) return (c * c) % MOD;
	return ((c * c) % MOD * a % MOD) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		ll a, b, c;
		cin >> a >> b >> c;
		cout << expo(a, expo(b, c, M-1), M) << "\n";
	}
	return 0;
}