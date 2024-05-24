#include <bits/stdc++.h>
using namespace std;

// 9/100

#define ll long long

ll A[100009], B[100009], cost[200009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];
	int q;
	cin >> q;
	for (int i = 1; i <= 2*n; i++) cost[i] = 9e18;
	if (n > 10) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < 1<<n; i++) {
		for (int j = 0; j < 1<<n; j++) {
			bool valid=true;
			for (int k = 0; k < n; k++) {
				if (j&(1<<k) && !(i&(1<<k))) {
					valid = false;
					break;
				}
			}
			if (!valid) continue;
			int cnt=0;
			ll sum=0;
			for (int k = 0; k < n; k++) {
				if (i&(1<<k)) {
					sum += A[k];
					cnt++;
					// cout << A[k] << " ";
				}
			}
			// cout << "\n";
			for (int k = 0; k < n; k++) {
				if (j&(1<<k)) {
					sum += B[k];
					cnt++;
					// cout << B[k] << " ";
				}
			}
			// cout << "\n\n";
			cost[cnt] = min(cost[cnt], sum);
		}
	}
	while (q--) {
		ll x;
		cin >> x;
		cout << upper_bound(cost, cost+2*n, x)-cost-1 << "\n";
	}
	// for (int i = 0; i <= 2*n; i++) {
	// 	cout << i << " " << cost[i] << "\n";
	// }
	return 0;
}