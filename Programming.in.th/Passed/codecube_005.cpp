#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long int t, lcm=1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		lcm = t*lcm/__gcd(t, lcm);
	}
	cout << lcm;
	return 0;
}
