#include <bits/stdc++.h>
using namespace std;

int arr[1000007], dp[1000007];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q, a, b;
	cin >> n;
	cin >> arr[1];
	for (int i = 2; i <= n; i++) {
		cin >> arr[i];
		dp[i] = dp[i-1]+max(arr[i]-arr[i-1], 0);
	}
	cin >> q;
	while (q--) {
		cin >> a >> b;
		cout << dp[b]-dp[a] << "\n";
	}
	return 0;
}