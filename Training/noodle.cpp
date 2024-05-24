#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll e[100009];
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	ll l=5e5, r=0;
	for (int i = 1; i <= n; i++) {
		cin >> e[i];
		l = min(l, e[i]), r += e[i];
	}
	while (l < r) {
		ll mid=l+(r-l+1)/2, sum=0;
		int cnt=0;
		for (int i = 1; i <= n; i++) {
			sum += e[i];
			pq.push(e[i]);
			if ((int)pq.size() > k) sum -= pq.top(), pq.pop();
			if ((int)pq.size() == k && sum >= mid) {
				sum = 0, cnt++;
				while (!pq.empty()) pq.pop();
			}
		}
		while (!pq.empty()) pq.pop();
		if (cnt >= m) l = mid;
		else r = mid-1;
		// cout << mid << " " << cnt << " " << (cnt >= m ? "***" : "") << "\n";
	}
	cout << l;
	return 0;
}