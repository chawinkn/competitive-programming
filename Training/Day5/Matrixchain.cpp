#include <bits/stdc++.h>
using namespace std;

// DP MCM

int dp[19][19], path[19][19], row[19], col[19];

void print(int l, int r) {
	if (l == r) {
		cout << "A" << l+1;
		return;
	}
	cout << "(";
	print(l, path[l][r]);
	cout << " x ";
	print(path[l][r]+1, r);
	cout << ")";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> row[i] >> col[i];
	for (int sz = 1; sz < n; sz++) {
		for (int i = 0; i+sz < n; i++) {
			int j=i+sz;
			dp[i][j] = 1e9;
			for (int k = i; k < j; k++) {
				if (dp[i][k]+dp[k+1][j]+row[i]*col[k]*col[j] < dp[i][j]) {
					dp[i][j] = dp[i][k]+dp[k+1][j]+row[i]*col[k]*col[j];
					path[i][j] = k;
				}
			}
		}
	}
	cout << dp[0][n-1] << "\n";
	print(0, n-1);
	return 0;
}