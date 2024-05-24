#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

ll dp[100009], x[100009], c[100009];
pair<int,int> arr[100009];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i].f >> arr[i].s;
	sort(arr+1, arr+n+1);
	for (int i = 1; i <= n; i++) x[i] = arr[i].f, c[i] = arr[i].s;
	priority_queue<pair<ll,int>> pq;
	for (int i = 1; i <= n; i++) {
		while (!pq.empty() && x[i]-x[pq.top().s] > k) pq.pop();
		dp[i] = dp[i-1];
		if (!pq.empty()) dp[i] = max(dp[i], pq.top().f+c[i]-x[i]);
		pq.push({dp[i-1]+c[i]+x[i], i});
	}
	cout << dp[n];
	return 0;
}