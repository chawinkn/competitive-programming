#include <bits/stdc++.h>
using namespace std;

const int M = 1e6+3;
char arr[309][309];
int dp[309][309], C[609][609];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int r, c, k;
	cin >> r >> c >> k;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '#') dp[i][j] = 1;
		}
	}
	C[0][0] = 1;
	for (int i = 1; i <= 609; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) C[i][j] = (C[i-1][j]+C[i-1][j-1])%M;
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) dp[i][j] += dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
	}
	return 0;
}
