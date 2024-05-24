#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ans[59];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q, a;
	cin >> q;
	ans[1] = 69;
	for (int i = 2; i <= 55; i++) {
		if (i%2 == 0) ans[i] = ans[i-1]+i;
		else ans[i] = ans[i-1]+ans[i-2]+i;
	}
	while (q--) {
		cin >> a;
		cout << ans[a] << "\n";
	}
	return 0;
}
