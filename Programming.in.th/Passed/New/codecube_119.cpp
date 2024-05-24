#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int arr[109][10009], dp[109][10009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (i == 1) dp[i][j] = arr[i][j];
			else dp[i][j] = -1e9;
		}
	}
	for (int i = 1; i < n; i++) {
		priority_queue<pair<int,int>> pq;
		for (int j = 1; j <= k+1; j++) pq.push({dp[i][j], j});
		for (int j = 1; j <= m; j++) {
			while (!pq.empty() && j-pq.top().s > k) pq.pop();
			dp[i+1][j] = pq.top().f+arr[i+1][j];
			if (j+k+1 <= m) pq.push({dp[i][j+k+1], j+k+1});
		}
	}
	int ans=0;
	for (int i = 1; i <= m; i++) ans = max(ans, dp[n][i]);
	cout << ans;
	return 0;
}
