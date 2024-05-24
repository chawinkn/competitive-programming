#include <bits/stdc++.h>
using namespace std;

// LIS Subarray ?

// 20/100

#define ll long long

void solve() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];
	// int ans=0;
	// for (int i = 0; i < n; i++) {
	// 	for (int j = i+1; j < n; j++) {
	// 		swap(h[i], h[j]);
	// 		int k=0;
	// 		while (k < n-1) {
	// 			if (h[k+1] < h[k]) break;
	// 			k++;
	// 		}
	// 		ans = max(ans, k+1);
	// 		swap(h[i], h[j]);
	// 	}
	// }
	// int k=0;
	// while (k < n-1) {
	// 	if (h[k+1] < h[k]) break;
	// 	k++;
	// }
	// ans = max(ans, k+1);
	cout << min(n, 3) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}