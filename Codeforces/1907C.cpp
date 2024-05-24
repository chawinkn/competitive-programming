#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	string in;
	cin >> t;
	while (t--) {
		cin >> n >> in;
		int cnt[26]={0}, mx=0;
		for (auto i : in) cnt[i-'a']++;
		for (int i = 0; i < 26; i++) mx = max(mx, cnt[i]);
		if (mx > n/2) cout << 2*mx-n;
		else cout << n%2;
		cout << "\n";
	}
	return 0;
}