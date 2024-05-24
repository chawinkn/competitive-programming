#include <bits/stdc++.h>
using namespace std;

string s[30009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int l, n;
	cin >> l >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i < n; i++) {
		int cnt=0;
		for (int j = 0; j < l; j++) {
			if (s[i][j] != s[i+1][j]) cnt++;
		}
		if (cnt > 2) {
			cout << s[i];
			return 0;
		}
	}
	cout << s[n];
	return 0;
}