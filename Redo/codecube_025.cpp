#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll qs[609], dp[609][609];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> qs[i], qs[i] += qs[i-1];
	for (int sz = 1; sz <= n; sz++) {
		for (int i = 1; i+sz-1 <= n; i++) {
			int j=i+sz-1;
			for (int k = i; k < j; k++) {
				ll A=qs[k]-qs[i-1], B=qs[j]-qs[k];
				dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]+2*min(A,B)+max(A,B));
			}
		}
	}
	cout << dp[1][n];
	return 0;
}