#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

ll dp[100009];
int X[100009], C[100009];
deque<pair<ll,int>> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<pair<int,int>> v(n+1);
	for (int i = 1; i <= n; i++) {
		int x, c;
		cin >> x >> c;
		v[i] = {x, c};
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		auto [x,c] = v[i];
		X[i] = x, C[i] = c;
	}
	// dq (val, idx)
	for (int i = 1; i <= n; i++) {
		while (!dq.empty() && X[i]-X[dq.front().s] > k) dq.pop_front();
		
		dp[i] = dp[i-1];
		if (!dq.empty()) dp[i] = max(dp[i], dq.front().f+C[i]-X[i]);

		while (!dq.empty() && dp[i-1]+C[i]+X[i] >= dq.back().f) dq.pop_back(); 
		dq.push_back({dp[i-1]+C[i]+X[i], i});
		
		// dp[i] = max dp[j-1]+Cj+Xj + Ci-Xi
		//        1<j<i
	}
	cout << dp[n];
	return 0;
}