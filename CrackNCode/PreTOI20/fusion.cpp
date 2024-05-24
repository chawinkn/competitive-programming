#include <bits/stdc++.h>
using namespace std;

#define ll long long

// 83/100 (after contest)

ll a[2009];
bool dp[2][4000009];
queue<ll> Q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	int sum=0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		Q.push(a[i]);
	}
	ll ans=0;
	while (Q.size() > 1) {
		ll a=Q.front(); Q.pop();
		ll b=Q.front(); Q.pop();
		ans += a*b;
		Q.push(a+b);
	}
	if (q == 0) {
		cout << ans;
		return 0;
	}
	dp[0][0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			dp[i%2][j] = dp[(i-1)%2][j];
			if (j >= a[i]) dp[i%2][j] |= dp[(i-1)%2][j-a[i]];
		}
	}
	ll mx=0;
	for (int i = 1; i < sum; i++) {
		if (dp[n%2][i]) mx = max(mx, (ll)i*(ll)(sum-i));
	}
	cout << ans-mx << "\n";
	return 0;
}