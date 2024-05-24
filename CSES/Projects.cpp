#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
#define ll long long
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<pair<int,int>,ll>> proj(n+1);
	for (int i = 1; i <= n; i++) cin >> proj[i].f.s >> proj[i].f.f >> proj[i].s;
	sort(proj.begin()+1, proj.end());
	
	vector<int> end(n+1);
	for (int i = 1; i <= n; i++) end[i] = proj[i].f.f;
	vector<ll> dp(n+1);
	for (int i = 1; i <= n; i++) {
		int idx=lower_bound(end.begin(), end.end(), proj[i].f.s)-end.begin()-1;
		dp[i] = max(dp[i-1], proj[i].s+dp[idx]);
	}
	cout << dp[n];
	return 0;
}