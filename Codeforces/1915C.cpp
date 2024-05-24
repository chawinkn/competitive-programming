#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		long long a, sum=0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			sum += a;
		}
		bool can=false;
		for (long long i = 1; i*i <= sum; i++) {
			if (i*i == sum) {
				can=true;
				break;
			}
		}
		if (can) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
Click to se