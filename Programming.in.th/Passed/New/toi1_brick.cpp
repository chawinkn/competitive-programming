#include <bits/stdc++.h>
using namespace std;

string s[29];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int j = 0; j < m; j++) {
		int b=n, cnt;
		cin >> cnt;
		for (int i = 0; i < n; i++) {
			if (s[i][j] == 'O') {
				b = i;
				break;
			}
		}
		for (int i = b-1; i >= 0 && cnt > 0; i--, cnt--) s[i][j] = '#';
	}
	for (int i = 0; i < n; i++) cout << s[i] << "\n";
	return 0;
}