#include <bits/stdc++.h>
using namespace std;

int ax[109], ay[109], bx[109], by[109], sum=0;

int main() {
	int n, m, a, b, ans=0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a;
			ax[i] += a;
			ay[j] += a;
			sum += a;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> b;
			bx[i] += b;
			by[j] += b;
		}
	}
	for (int i = 1; i <= n; i++) ans = max(ans, sum-ax[i]+bx[i-1]+bx[i+1]);
	for (int i = 1; i <= m; i++) ans = max(ans, sum-ay[i]+by[i-1]+by[i+1]);
	cout << ans;
	return 0;
}
