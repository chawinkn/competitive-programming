#include <bits/stdc++.h>
using namespace std;

int arr[1009];
vector<vector<int>> dp(1009, vector<int>(59, 1e9));

int main() {
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 0; i <= 50; i++) {
		dp[0][i] = 0;
		if (i > 0) dp[1][i] = (x+y)*i;	
	}
	for (int i = 2; i <= n; i++) {
		for (int j = arr[i]; j <= 50; j++) {
			for (int k = arr[i-1]; k <= 50; k++) {
				if (k <= j) dp[i][j] = min(dp[i][j], dp[i-1][k]+(j-k)*x+y*j);
				else dp[i][j] = min(dp[i][j], dp[i-1][k]+(k-j)*z+y*j);
			}
		}
	}
	int ans=1e9;
	for (int i = arr[n]; i <= 50; i++) ans = min(ans, dp[n][i]);
	cout << ans;
	return 0;
}
