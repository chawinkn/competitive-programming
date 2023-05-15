#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, r1, r2, cnt, ans;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		m = s.length();
		r1 = 0;
		r2 = m+1;
		cnt = 0;
		for (int i = m-1; i >= 0; i--) {
			if (s[i] == 'R') {
				r2 = i+1;
				cnt++;
				break;
			}
		}
		for (int i = 0; i < m; i++) {
			if (s[i] == 'R' && i+1 != r2) {
				r1 = i+1;
				cnt++;
				break;
			}
		}
		if (cnt == m) cout << 1;
		else cout << r2-r1 << "\n";
	}
}
