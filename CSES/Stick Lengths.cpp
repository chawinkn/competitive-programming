#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) cin >> p[i];
	sort(p.begin(), p.end());
	int m=n/2;
	ll ans=0;
	for (int i = 0; i < n; i++) ans += abs(p[i]-p[m]);
	cout << ans;
	return 0;
}