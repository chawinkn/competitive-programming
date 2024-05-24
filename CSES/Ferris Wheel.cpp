#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	vector<int> a(n), v(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int i=0, j=n-1, ans=0;
	while (i < j) {
		if (a[i]+a[j] <= x) {
			v[i] = v[j] = true;
			i++, j--, ans++;
		}
		else j--;
	}
	cout << n-ans; // ans+(n-2*ans)
	return 0;
}