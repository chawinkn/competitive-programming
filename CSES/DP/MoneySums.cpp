#include <bits/stdc++.h>
using namespace std;

int x[1009];
bool dp[2][100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, sum=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		sum += x[i];
	}
	dp[0][0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			dp[i%2][j] |= dp[(i-1)%2][j];
			if (j < x[i]) continue;
			dp[i%2][j] |= dp[(i-1)%2][j-x[i]];
		}
	}
	int cnt=0;
	vector<int> ans;
	for (int i = 1; i <= sum; i++) {
		if (dp[n%2][i]) {
			cnt++;
			ans.push_back(i);
		}
	}
	cout << cnt << "\n";
	for (auto i : ans) cout << i << " ";
	return 0;
}