#include <bits/stdc++.h>
using namespace std;

int x[109][109], y[109][109];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> x[1][i];
	for (int i = 2; i <= n+1; i++) {
		for (int j = 1; j <= n+1; j++) cin >> y[i][j];
		for (int j = 1; j <= n; j++) cin >> x[i][j];
	}
	priority_queue<int> pq;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			pq.push(-(3*x[i][j]+5*y[i+1][j]-3*x[i+1][j]-5*y[i+1][j+1]));
		}
	}
	int ans=0;
	for (int i = 0; i < k; i++) ans -= pq.top(), pq.pop();
	cout << ans;
	return 0;
}
