#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll qs[6000009];
deque<int> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, w;
	cin >> n >> w;
	for (int i = 1; i <= n; i++) cin >> qs[i], qs[i] += qs[i-1];
	ll ans=0;
	int sz=n;
	dq.push_back(0);
	for (int i = 1; i <= n; i++) {
		while (!dq.empty() && i-dq.front() > w) dq.pop_front();
		while (!dq.empty() && qs[i] <= qs[dq.back()]) dq.pop_back();
		dq.push_back(i);
		ll sum=qs[i]-qs[dq.front()];
		int l=i-dq.front();
		if (sum > ans) {
			ans = sum;
			sz = l;
		}
		else if (sum == ans) sz = min(sz, l);
	}
	cout << ans << "\n" << sz;
	return 0;
}