#include <bits/stdc++.h>
using namespace std;

int arr[1009], dp[1009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}
	cout << n-dp[n];
	return 0;
}
