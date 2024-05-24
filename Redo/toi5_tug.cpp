#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) cin >> y[i];
	ll ans=0;
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for (int i = 0; i < n; i++) ans += abs(x[i]-y[i]);
	cout << ans;
	return 0;
}