#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	int ans=0;
	while (pq.size() > 1 && pq.top() < k) {
		int a=pq.top(); pq.pop();
		int b=pq.top(); pq.pop();
		pq.push(116*(a+b)/100);
		ans++;
	}
	cout << ans;
	return 0;
}