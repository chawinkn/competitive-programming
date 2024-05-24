#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
   	int n, m, x;
   	cin >> n >> m;
   	vector<int> a(n);
   	for (int i = 0; i < n; i++) cin >> a[i];
   	sort(a.begin(), a.end());
   	while (m--) {
   		cin >> x;
   		int l=0, r=n-1, idx=n;
   		while (l <= r) {
   			int m=(l+r)/2;
   			if (a[m] > x) {
   				idx = m;
				r = m-1;
			}
			else l = m+1;
	    }
		cout << (idx == 0 ? -1 : idx-1) << "\n";
//	   	auto it=upper_bound(a.begin(), a.end(), x);
//	   	cout << (it == a.begin() ? -1 : *(--it)) << "\n";
	}
    return 0;
}