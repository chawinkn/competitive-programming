#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	long long int x, M=1e9+7;
	cin >> q;
	while (q--) {
		cin >> x;
		if (x == 1 || x == 2) cout << "NO\n";
		else cout << ((x%M)-3)%M << "\n";
	}
	return 0;
}
