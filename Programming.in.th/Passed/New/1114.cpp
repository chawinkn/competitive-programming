#include <bits/stdc++.h>
using namespace std;

int w[609][609];
vector<int> dp(609, 1e9);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= 2*n; i++) {
		for (int j = 1; j <= 2*n; j++) {
			cin >> w[i][j];
		}
	}
	dp[2] = 0; // 2 -> 2 = 0
	for (int i = 3; i <= 2*n; i++) { // r+c
		for (int j = 2; j < i; j++) { // r'+c'
			dp[i] = min(dp[i], dp[j]+w[i][j]);
		}
	}
	cout << dp[2*n]; // 2*n -> 2
	return 0;
}