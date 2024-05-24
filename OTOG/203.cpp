#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, p1, p2, tmp;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2;
		tmp = a[p1-1];
		a[p1-1] = a[p2-1];
		a[p2-1] = tmp;
	}
	for (int i = 0; i < n; i++) {
	    cout << a[i] << " ";
	}
	return 0;
}
