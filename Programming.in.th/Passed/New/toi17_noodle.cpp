#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll e[100009];

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
		ll mid=l+(r-l+1)/2;
		ll sum=0, cnt=0;
		priority_queue<ll> pq;
		for (int i = 1; i <= n; i++) {
			sum += e[i];
			pq.push(-e[i]);
			if (pq.size() > k) {
				sum += pq.top();
				pq.pop();
			}
			if (sum >= mid && pq.size() == k) {
				sum = 0;
				cnt++;
				while (!pq.empty()) pq.pop();
			}
		}
		if (cnt >= m) l = mid; 
		else r = mid-1;
	}
	cout << l;
	return 0;
}