#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll qs[1000009], dp[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> qs[i];
		qs[i] += qs[i-1];
	}
	deque<int> dq;
	dq.push_back(0);
	for (int i = 1; i <= n; i++) {
		while (!dq.empty() && qs[i]-qs[dq.front()] > k) dq.pop_front();
		while (!dq.empty() && dp[i-1] > dp[max(dq.back()-1,0)]+qs[i]-qs[dq.back()]) dq.pop_back();
		dq.push_back(i);
		dp[i] = dp[max(dq.front()-1,0)]+qs[i]-qs[dq.front()];
	}
	cout << dp[n];
	return 0;
}
