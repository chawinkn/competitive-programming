#include <bits/stdc++.h>
using namespace std;

string s[21];

int main() {
	int n, m, a, block;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];	
	for (int i = 0; i < m; i++) {
		cin >> a;	
		block = n;
		for (int j = 0; j < n; j++) {
			if (s[j][i] == 'O') {
				block = j;
				break;
			}
		}
		for (int j = block-1; j >= 0 && a > 0; j--, a--) {
			s[j][i] = '#';
		}
	}
	for (auto i : s) cout << i << "\n";
	return 0;
}
