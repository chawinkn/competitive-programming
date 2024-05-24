#include <bits/stdc++.h>
using namespace std;

int n, dp[1009][1009];
vector<tuple<int,int,int>> t;
vector<int> start;

int solve(int i, int j) {
	if (i >= n) return 0;
	if (dp[i][j]) return dp[i][j];
	auto [s,e,v] = t[i];
	dp[i][j] = solve(i+1, j);
	int idx=lower_bound(start.begin()+i+1, start.end(), min(j, e))-start.begin();
	dp[i][j] = max(dp[i][j], solve(idx, max(j, e))+v);
	return dp[i][j];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p, k, v;
		cin >> p >> k >> v;
		t.push_back({p, k, v});
	}
	sort(t.begin(), t.end());
	for (auto [s,e,v] : t) start.push_back(s);
	cout << solve(0, 0);
	return 0;
}