#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<int> t[2007];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, v;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> v;
			t[i+j-2].push_back(v);
		}
	}
	priority_queue<int> pq;
	int ans=0;
	for (int i = 2*n-2; i >= 1; i--) {
		for (auto i : t[i]) pq.push(i);
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
	return 0;
}