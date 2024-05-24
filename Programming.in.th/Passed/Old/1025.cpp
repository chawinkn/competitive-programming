#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long int a, lcm=1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		lcm = a*lcm/gcd(a, lcm);
	}
	cout << lcm;
	return 0;
}
