#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> h(n+2), H, ans;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) {
		if (h[i] > h[i-1] && h[i] > h[i+1]) H.push_back(h[i]);
	}
	sort(H.begin(), H.end());
	H.push_back(0);
	for (int i = H.size()-2, K = k; i >= 0 && K; i--) {
		if (H[i] != H[i+1]) {
			ans.push_back(H[i]);
			K--;
		}
	}
	n = ans.size();
	if (n == 0) cout << -1;
	else {
		if (n < k) reverse(ans.begin(), ans.end());
		for (auto i : ans) cout << i << "\n";
	}
	return 0;	
}