#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[200009];
int n, h[200009], a[200009];

// ก๊อป fenwick มา 🤡

void update(int i, long long v) {
	for (; i <= n; i+=i&-i) {
		dp[i] = max(dp[i], v);
	}
}

ll query(int i) {
	ll ans=0;
	for (; i; i-=i&-i) {
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		// dp[i] = a[i];
		// for (int j = 1; j < i; j++) {
		// 	if (h[i] > h[j]) dp[i] = max(dp[i], dp[j]+a[i]);
		// }
		update(h[i], query(h[i]-1)+a[i]);
	}
	// cout << dp[n];
	cout << query(n);
	return 0;
}