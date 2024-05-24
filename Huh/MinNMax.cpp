#include <bits/stdc++.h>
using namespace std;

int dp[29][29], DP[29][29];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		vector<int> num;
		vector<char> op;
		int temp=0;
		for (auto i : s) {
			if (i == '+' || i == '*') {
				num.push_back(temp);
				op.push_back(i);
				temp = 0;	
			}
			else {
				temp *= 10;
				temp += i-'0';
			}
		}
		num.push_back(temp);
		int n=num.size();
		for (int i = 0; i < n; i++) dp[i][i] = DP[i][i] = num[i];
		// num[i] op[i] num[i+1]
		for (int sz = 2; sz <= n; sz++) {
			for (int i = 0; i+sz-1 < n; i++) {
				int j = i+sz-1;
				dp[i][j] = 1e9, DP[i][j] = 0;
				for (int k = i; k < j; k++) {
					if (op[k] == '+') {
						dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);	
						DP[i][j] = max(DP[i][j], DP[i][k]+DP[k+1][j]);	
					}
					else {
						dp[i][j] = min(dp[i][j], dp[i][k]*dp[k+1][j]);	
						DP[i][j] = max(DP[i][j], DP[i][k]*DP[k+1][j]);
					}
				}
			}
		}
		cout << dp[0][n-1] << " " << DP[0][n-1] << "\n";
	}
	return 0;
}