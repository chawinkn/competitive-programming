#include <bits/stdc++.h>
using namespace std;

int a[200003], b[200003];

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	sort(a, a+n);
	sort(b, b+m);
	int cnt=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[j] >= a[i]-k && b[j] <=z a[i]+k) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
