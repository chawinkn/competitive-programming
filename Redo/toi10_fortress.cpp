#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q=20;
	while (q--) {
		int m, n;
		cin >> m >> n;
		if (m < 2*n || m > 4*n) cout << "0\n";
		else cout << 2*n-m/2+1 << "\n";
	}
	return 0;
}