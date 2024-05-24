#include <bits/stdc++.h>
using namespace std;

int c[509];
bool dp[2][509][509];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, K;
	cin >> n >> K;
	for (int i = 1; i <= n; i++) cin >> c[i];
	dp[0][0][0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= K; j++) {
			for (int k = 0; k <= K; k++) {
				dp[i%2][j][k] = dp[(i-1)%2][j][k];
				if (j >= c[i]) {
					dp[i%2][j][k] |= dp[(i-1)%2][j-c[i]][k];
					if (k >= c[i]) dp[i%2][j][k] |= dp[(i-1)%2][j-c[i]][k-c[i]];
				}
			}
		}
	}
	vector<int> ans;
	for (int x = 0; x <= K; x++) {
		if (dp[n%2][K][x]) ans.push_back(x);
	}
	cout << ans.size() << "\n";
	for (auto x : ans) cout << x << " ";
	return 0;
}