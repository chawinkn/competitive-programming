#include <bits/stdc++.h>
using namespace std;

int qs[6000009];
deque<int> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, w;
	cin >> n >> w;
	for (int i = 1; i <= n; i++) {
		cin >> qs[i];
		qs[i] += qs[i-1];
	}
	dq.push_back(0);
	int ans=0, l=0;
	for (int i = 1; i <= n; i++) {
		while (!dq.empty() && i-dq.front() > w) dq.pop_front();
		while (!dq.empty() && qs[i] <= qs[dq.back()]) dq.pop_back();
		int sum=qs[i]-qs[dq.front()];
		if (sum > ans) {
			ans = sum;
			l = i-dq.front();
		}
		if (sum == ans) l = min(l, i-dq.front());
		dq.push_back(i);
	}
	cout << ans << "\n" << l;
	return 0;
}