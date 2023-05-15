#include <bits/stdc++.h>
using namespace std;

int t[500001], h[500001], sum[500001];

int main() {
	int n;
	long long int ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> t[i];
	for (int i = 0; i < n; i++) cin >> h[i];
	sort(t, t+n);
	sort(h, h+n);
	for (int i = 0; i < n; i++) sum[i] = t[i]+h[n-i-1];
	sort(sum, sum+n);
	for (int i = 1; i < n; i++) ans += sum[i]-sum[i-1];
	cout << ans;
	return 0;
}
