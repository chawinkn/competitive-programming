#include <bits/stdc++.h>
using namespace std;

int l[1000009], r[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> l[i];
	for (int i = n; i > 0; i--) r[i] = max(r[i+1], l[i]);
	int mx=0;
	for (int i = 1; i < n; i++) {
		mx = max(mx, l[i]);
		cout << min(mx, r[i+1]) << " ";	
	}
	return 0;
}