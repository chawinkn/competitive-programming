#include <bits/stdc++.h>
using namespace std;

// D&C

int mod(int A, int B, int C) {
	if (B == 1) return A % C;
	int res = mod(A, B/2, C);
	if (B%2 == 0) return (res * res) % C;
	return ((res * res) % C * A % C) % C;
}

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << mod(a, b, c) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}