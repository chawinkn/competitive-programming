#include <bits/stdc++.h>
using namespace std;

int x[2001], y[2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long int ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) cin >> y[i];
	
	sort(x, x+n);
	sort(y, y+n);
	for (int i = 0; i < n; i++) ans += abs(x[i]-y[i]);
	cout << ans;
	return 0;
}

