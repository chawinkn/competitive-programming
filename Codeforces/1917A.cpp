#include <bits/stdc++.h>
using namespace std;
 
int arr[109];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int zero=0, neg=0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (arr[i] < 0) neg++;
			if (arr[i] == 0) zero++;
		}
		if (zero || neg%2 == 1) cout << 0 << "\n";
		else {
			int idx=1;
			if (neg != 0) {
				for (int i = 1; i <= n; i++) {
					if (arr[i] < 0) {
						idx = i;
						break;
					}
				}
			}
			cout << "1\n" << idx << " 0\n";
		}
	}
	return 0;
}