#include <bits/stdc++.h>
using namespace std;

// 20/100

#define ll long long

ll qs[5009], dp[2][5009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> qs[i], qs[i] += qs[i-1];
	ll ans=0;
	for (int i = 1; i <= n; i++) {
		memset(dp[i%2], 0, sizeof(dp[i%2]));
		for (int j = 1; j+i-1 <= n; j++) {
			for (int k = 1; k+i-2 <= n; k++) {
				ll val = qs[j+i-1]-qs[j-1];
				if (k <= j+i-1 && k+i-2 >= j) val /= 2;
				dp[i%2][j] = max(dp[i%2][j], dp[(i-1)%2][k]+val);
			}
			if (i == n) ans = max(ans, dp[i%2][j]);
		}
	}
	cout << ans;
	return 0;
}