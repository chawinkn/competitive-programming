#include <bits/stdc++.h>
using namespace std;

// Greedy

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> t(n);
	for (int i = 0; i < n; i++) cin >> t[i];
	sort(t.begin(), t.end());
	int ans=0;
	for (int i = n-1; i >= 0; i-=k) ans += t[i];
	cout << ans;
	return 0;
}