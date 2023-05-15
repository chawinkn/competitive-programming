#include <bits/stdc++.h>
using namespace std;

int d;

void permutation(int l, string s) {
	if (l == d) {
		for (int i = l-1; i >= 0; i--) {
			if (s[i] == '0') {
				cout << s << " ";
				for (int j = 0; j < l; j++) {
					if (j == i) cout << "1";
					else cout << s[j];
				}
				cout << "\n";
			}
		}
		return;
	}
	permutation(l+1, s+"0");
	permutation(l+1, s+"1");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> d;
	permutation(0, "");
	return 0;
}
