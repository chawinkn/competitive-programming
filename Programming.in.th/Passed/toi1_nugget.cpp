#include <bits/stdc++.h>
using namespace std;

int dp[101];

int main() {
	int n;
	cin >> n;
	dp[6] = 1;
	dp[9] = 1;
	dp[20] = 1;
	for (int i = 12; i <= n; i++) {
		if (dp[i-6] || dp[i-9] || dp[i-20]) {
			dp[i] = 1;	
		}
	}
	if (n >= 6) {
		for (int i = 6; i <= n; i++) {
			if (dp[i]) {
				cout << i << "\n";
			}
		}
	}
	else cout << "no";
	return 0;
}
