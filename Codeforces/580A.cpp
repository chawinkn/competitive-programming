#include <bits/stdc++.h>
using namespace std;

int dp[100009], arr[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, ans=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] >= arr[i-1]) dp[i] = dp[i-1]+1;
		else dp[i] = 1;
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}