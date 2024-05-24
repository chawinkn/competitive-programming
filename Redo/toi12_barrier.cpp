#include <bits/stdc++.h>
using namespace std;

int qs[6000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, w;
	cin >> n >> w;
	for (int i = 1; i <= n; i++) {
		cin >> qs[i];
		qs[i] += qs[i-1];
	}
	deque<int> dq;
	dq.push_back(0);
	int mx=0, l=0;
	for (int i = 1; i <= n; i++) {
		while (!dq.empty() && i-dq.front() > w) dq.pop_front();
		while (!dq.empty() && qs[i] <= qs[dq.back()]) dq.pop_back();
		int sum=qs[i]-qs[dq.front()], k=i-dq.front();
		if (sum > mx) {
			mx = sum;
			l = k;
		}
		else if (sum == mx) l = min(l, k);
		dq.push_back(i);
	}
	cout << mx << "\n" << l;
	return 0;
}