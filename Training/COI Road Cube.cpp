#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int cube[109][10009], dp[109][10009];
// priority_queue<pair<int,int>> pq;
deque<pair<int,int>> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, K;
	cin >> n >> m >> K;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> cube[i][j];
			if (i == 1) dp[1][j] = cube[1][j];
		}
	}
	for (int i = 2; i <= n; i++) {
		// while (!pq.empty()) pq.pop();
		while (!dq.empty()) dq.pop_back();
		for (int j = 1; j <= min(m,K+1); j++) {
			// pq.push({dp[i-1][j], j});

			while (!dq.empty() && dp[i-1][j] >= dq.back().f) dq.pop_back();
			dq.push_back({dp[i-1][j], j});
		}
		for (int j = 1; j <= m; j++) {
			// while (!pq.empty() && j-pq.top().s > K) pq.pop();
			// dp[i][j] = pq.top().f+cube[i][j];
			// if (j+K+1 <= m) pq.push({dp[i-1][j+K+1], j+K+1});
			
			while (!dq.empty() && j-dq.front().s > K) dq.pop_front();
			dp[i][j] = (!dq.empty() ? dq.front().f : 0)+cube[i][j];
			
			if (j+K+1 > m) continue;
			while (!dq.empty() && dp[i-1][j+K+1] >= dq.back().f) dq.pop_back();
			dq.push_back({dp[i-1][j+K+1], j+K+1});
			
			// dp[i][j] =   max dp[i-1][k] + cube[i][j]
			// max(1,j-K) <= k <= min(m,j+K)
		}
	}
	int ans=0;
	for (int i = 1; i <= m; i++) ans = max(ans, dp[n][i]);
	cout << ans;
	return 0;
}