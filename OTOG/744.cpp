#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll qs[1000009];
deque<int> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	ll s;
	cin >> n >> s;
	int ans=n;
	for (int i = 1; i <= n; i++) cin >> qs[i], qs[i] += qs[i-1];
	dq.push_back(0);
	for (int i = 1; i <= n; i++) {
		// Shrinking window from front
		while (!dq.empty() && qs[i]-qs[dq.front()] >= s) {
			ans = min(ans, i-dq.front());
			dq.pop_front();
		}
		dq.push_back(i);
		// ll sum=0;
		// for (int j = i; j <= n; j++) {
		// 	sum += X[j];
		// 	if (sum >= s) ans = min(ans, j-i+1);
		// }
	}
	cout << ans;
	return 0;
}