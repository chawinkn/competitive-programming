#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		string s;
		cin >> n >> s;
		bool v[n]={false};
		for (int i = 0; i < n; i++) {
			if (s[i] == 'a' || s[i] == 'e') v[i] = true;
		}
		int i=0;
		string ans;
		while (i < n) {
			if (v[i]) {
				if (i+2 < n && v[i+2]) {
					ans += s[i], i++;
					if (i < n) ans += ".";
				}
				else {
					ans += s[i], i++;
					if (i < n) ans += s[i], i++;
					if (i < n) ans += ".";
				}
			}
			else {
				ans += s[i], i++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}