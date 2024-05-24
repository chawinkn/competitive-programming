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
	   	auto it=upper_bound(a.begin(), a.end(), x);
	   	cout << (it == a.begin() ? -1 : it-a.begin()-1) << "\n";
	}
    return 0;
}