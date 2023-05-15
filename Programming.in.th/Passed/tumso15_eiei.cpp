#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, q, n, k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> q;
		for (int j = 0; j < q; j++) {
			cin >> n >> k;
			if (n-k-1 <= 0) cout << -1;
			else {
				if (n%(k+1) == 0) cout << k+1 << " ";
				else cout << n%(k+1) << " ";
				cout << n-k-1;
			}
			cout << "\n";
		}
	}
	return 0;
}
