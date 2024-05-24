#include <bits/stdc++.h>
using namespace std;

int x[807], y[807];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, sum1=0, sum2=0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) cin >> y[i];
	sort(x, x+n); 
	sort(y, y+n);
	for (int i = 0; i < n; i++) {
		sum1 += x[i]*y[n-i-1];
		sum2 += x[n-i-1]*y[i];
	}
	cout << max(sum1, sum2);
	return 0;
}