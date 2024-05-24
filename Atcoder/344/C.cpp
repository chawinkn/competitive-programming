#include <bits/stdc++.h>
using namespace std;

set<int> s;
int a[109], b[109], c[109];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, l, q, x;
	cin >> n; 
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m; 
	for (int i = 0; i < m; i++) cin >> b[i];
	cin >> l; 
	for (int i = 0; i < l; i++) cin >> c[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < l; k++) s.insert(a[i]+b[j]+c[k]);
		}
	}
	cin >> q;
	while (q--) {
		cin >> x;
		cout << (s.find(x) != s.end() ? "Yes" : "No") << "\n";
	}
	return 0;
}