#include <bits/stdc++.h>
using namespace std;

// 12/100

const int M=1e9+7;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	if (n <= 3) cout << 0;
	else if (n == 4) cout << (k == 1 ? 1 : 0);
	else {
		// wrong lol
		ll ans=0;
		for (int i = 1; i <= n-3; i++) {
			for (int j = i+2; j <= n-1; j++) {
				ans += (j-i-1)*(n-j);
				ans %= M;
				cout << i << " " << j << "\n";
			}
		}
		cout << ans;
	}
	return 0;
}