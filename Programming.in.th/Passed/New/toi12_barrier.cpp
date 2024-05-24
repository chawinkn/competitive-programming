#include <bits/stdc++.h>
using namespace std;

int qs[6000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, w, ans=0, sz=0;
	cin >> n >> w;
	for (int i = 1; i <= n; i++) {
		cin >> qs[i];
		qs[i] += qs[i-1];
	}
	deque<int> dq;
	dq.push_back(0);
	for (int i = 1; i <= n; i++) {
		while (!dq.empty() && i-dq.front() > w) dq.pop_front();
		while (!dq.empty() && qs[i] <= qs[dq.back()]) dq.pop_back();
		dq.push_back(i);
		int sum=qs[i]-qs[dq.front()];
		if (sum > ans) {
			ans = sum;
			sz = i-dq.front();
		}
		else if (sum == ans) sz = min(sz, i-dq.front());
	}
	cout << ans << "\n" << sz;
	return 0;
}
