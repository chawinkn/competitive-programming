#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, k;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> k >> s;
		int cnt=0, x=0;
		for (auto i : s) {
			if (i == 'B') cnt++;
		}
		if (cnt == k) cout << "0\n";
		else if (cnt < k) { // Add B
			int a=0;
			for (int i = 0; i < n; i++) {
				if (s[i] == 'A') a++;
				if (a+cnt == k) {
					cout << "1\n" << i+1 << " B\n";
					break;
				}
			}
		}
		else { // Add A
			int b=0;
			for (int i = 0; i < n; i++) {
				if (s[i] == 'B') b++;
				if (cnt-b == k) {
					cout << "1\n" << i+1 << " A\n";
					break;
				}
			}
		}
	}
	return 0;
}