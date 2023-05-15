#include <bits/stdc++.h>
using namespace std;

int n, s[11], b[11], m=1e9;

void perket(int i, int ss, int bb) {
	if (i == n) {
		if (bb != 0) m = min(m, abs(ss-bb));
	}
	else {
		perket(i+1, ss, bb);
		perket(i+1, ss*s[i], bb+b[i]);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i] >> b[i];
	perket(0, 1, 0);
	cout << m;
	return 0;
}
