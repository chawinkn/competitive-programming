#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long

pair<ll,ll> dp[89][89];
ll p[89][89], r[89][89], d[89][89];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> p[i][j];
			dp[i][j] = {1e18, 0};
		}
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j < n; j++) cin >> r[i][j];
	for (int i = 1; i < n; i++) for (int j = 1; j <= n; j++) cin >> d[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j].
		}
	}
	cout << dp[n][n].f;
	return 0;
}