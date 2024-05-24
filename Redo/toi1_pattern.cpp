#include <bits/stdc++.h>
using namespace std;

bool pattern[50009][70];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, p, q, r;
	cin >> n;
	int mx=0;
	while (n--) {
		cin >> p >> q >> r;
		for (int i = q-1; i < min(70, q+r-1); i++) {
			pattern[p-1][i] = true;
		}
		mx = max(mx, p);
	}
	for (int i = 0; i < mx; i++) {
		for (int j = 0; j < 70; j++) {
			cout << (pattern[i][j] ? 'x' : 'o');
		}
		cout << "\n";
	}
	return 0;
}