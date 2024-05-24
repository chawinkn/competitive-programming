#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int MAX_N = 20;
int n, x, w[MAX_N+9];
pair<int,int> dp[(1<<MAX_N)+9];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> w[i];

	dp[0] = {1, 0};
	for (int i = 1; i < (1<<n); i++) {
		dp[i] = {n+1, 0};
		for (int j = 0; j < n; j++) {
			if (!(i&(1<<j))) continue;

			auto prev = dp[i^(1<<j)];
			if (prev.s+w[j] <= x) {
				prev.s += w[j]; // add to existing ride
			}
			else { 
				prev.f++, prev.s = w[j]; // reserve a new ride
			}
			dp[i] = min(dp[i], prev);
		}
	}
	cout << dp[(1<<n)-1].f;
	return 0;
}