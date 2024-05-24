#include <bits/stdc++.h>
using namespace std;
 
int f[123459], s[123459];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, mn=20000, ans=0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
		mn = min(mn, f[i]);
	}
	for (int i = 1; i <= m; i++) {
		cin >> s[i];	
		ans += min(mn, s[i])*n;
	}
	cout << ans;
	return 0;
}