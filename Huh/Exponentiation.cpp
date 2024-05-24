#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int M=1e9+7;

// a*b mod m = (a mod m * b mod m) mod m

ll expo(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a % M;
	ll c=expo(a, b/2);
	if (b%2 == 0) return (c * c) % M;
	return ((c * c) % M * a % M) % M;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		cout << expo(a, b) << "\n";
	}
	return 0;
}