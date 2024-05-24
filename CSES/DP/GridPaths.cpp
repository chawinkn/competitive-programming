#include <bits/stdc++.h>
using namespace std;
 
#define M 1000000007
 
char arr[1009][1009];
int dp[1009][1009];
 
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	dp[1][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == '.') {
				dp[i][j] = (dp[i][j-1]+dp[i-1][j])%M;
			}
		}
	}
	cout << dp[n][n];
	return 0;
}
