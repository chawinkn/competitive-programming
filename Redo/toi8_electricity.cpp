#include <bits/stdc++.h>
using namespace std;

int dp[500009], p[500009];
deque<int> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> p[i];
	dp[1] = p[1];
	dq.push_back(1);
	for (int i = 2; i <= n; i++) {
		while (!dq.empty() && i-dq.front() > k) dq.pop_front();
		dp[i] = dp[dq.front()]+p[i];
		while (!dq.empty() && dp[dq.back()] >= dp[i]) dq.pop_back();
		dq.push_back(i);
	}
	cout << dp[n];
	return 0;
}