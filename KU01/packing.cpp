#include <bits/stdc++.h>
using namespace std;

int main() {
	long long w, l, pack=0;
	int m, n;
	cin >> w >> l >> m >> n;
	for (int i = m; i <= n; i++) {
		pack = max(pack, i*(w/i)*l + (w-(i*(w/i)))*(i*(l/i)));
	}
	cout << w*l-pack;
	return 0;
}
