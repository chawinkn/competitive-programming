#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll qs[200009];
deque<int> dq;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) cin >> qs[i], qs[i] += qs[i-1];
	dq.push_back(0);
	ll ans=-1e18;
	for (int i = 1; i <= n; i++) {
		while (!dq.empty() && i-dq.front() > b) dq.pop_front();
		while (!dq.empty() && i-dq.front() >= a && qs[i-a] <= qs[dq.back()]) dq.pop_back();
		if (i >= a) dq.push_back(i-a);
		if (i-dq.front() >= a) ans = max(ans, qs[i]-qs[dq.front()]);
	}
	cout << ans;
	return 0;
}