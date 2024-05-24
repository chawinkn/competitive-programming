#include <bits/stdc++.h>
using namespace std;

int a[10009], dp[10009];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] <= a[j]) continue;
			dp[i] = max(dp[i], dp[j]+1);
		}
	}
	int ans=0;
	for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans;
	return 0;
}