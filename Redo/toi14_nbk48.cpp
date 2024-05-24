#include <bits/stdc++.h>
using namespace std;

int main() {
   	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> qs(n);
	for (int i = 0; i < n; i++) {
		cin >> qs[i];
		if (i > 0) qs[i] += qs[i-1];
	}
	for (int i = n-2; i >= 0; i--) {
		qs[i] = min(qs[i], qs[i+1]);
	}
	while (q--) {
		int x;
		cin >> x;
		cout << upper_bound(qs.begin(), qs.end(), x)-qs.begin() << "\n";
	}
   	return 0;
}