#include <bits/stdc++.h>
using namespace std;

int X[3009], Y[3009], dp[3009][3009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i];
	for (int i = 1; i <= N; i++) cin >> Y[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (X[i] == Y[j]) dp[i][j] = dp[i-1][j-1]+1; 
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout << dp[N][N];
	return 0;
}