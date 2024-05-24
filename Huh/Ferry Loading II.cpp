#include <bits/stdc++.h>
using namespace std;

int a[1449];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, t, m;
	cin >> n >> t >> m;
	for (int i = 0; i < m; i++) cin >> a[i];
	int i=0, ans=0;
	if (m%n == 0) {
		ans = a[n-1]+2*t;
		i = n;
	}
	else {
		ans = a[m%n-1]+2*t;
		i = m%n;
	}
	while (i < m) {
		ans = max(ans, a[i+n-1])+2*t;
		i += n;
	}
	cout << ans-t << " " << m/n+(m%n!=0) << "\n";
	return 0;
}