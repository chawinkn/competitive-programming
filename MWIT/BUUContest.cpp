#include <bits/stdc++.h>
using namespace std;

#define ll long long

priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int d, k;
	cin >> d >> k;
	ll ans=0;
	for (int i = 0; i < d; i++) {
		int n, b;
		cin >> n >> b;
		while (n--) {
			int p;
			cin >> p;
			pq.push(p-i*k);
		}
		int cnt=0;
		while (!pq.empty() && cnt < b) {
			ans += i*k+pq.top(), pq.pop();
			cnt++;
		}
	}
	cout << ans;
	return 0;
}