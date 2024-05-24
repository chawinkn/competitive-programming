#include <bits/stdc++.h>
using namespace std;

string p, c;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int l, n, founded=0;
	cin >> l >> n >> p;
	n--;
	while (n--) {
		cin >> c;
		if (founded) continue;
		int cnt=0;
		for (int i = 0; i < l; i++) {
			if (p[i] != c[i]) cnt++;
		}
		if (cnt > 2) founded = 1;
		else p = c;
	}
	cout << p;
	return 0;
}