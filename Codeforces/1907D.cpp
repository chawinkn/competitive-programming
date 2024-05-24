#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		pair<int,int> arr[200009];
		int l=0, r=1e9, ans=0;
		for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
		while (l < r) {
			int m=(l+r)/2, s=0, e=0;
			bool can=true;
			for (int i = 0; i < n; i++) {
				s = max(s-m, arr[i].first);
				e = min(e+m, arr[i].second);
				if (s > arr[i].second || e < arr[i].first) {
					can = false;
					break;
				}
			}
			if (can) r = m;
			else l = m+1;
		}
		cout << l << "\n";
	}
	return 0;
}