#include <bits/stdc++.h>
using namespace std;

int cnt[3];

int main() {
	string s, a="ABC", b="BABC", g="CCAABB";
	int n, m=0;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == a[i%3]) cnt[0]++;
		if (s[i] == b[i%4]) cnt[1]++;
		if (s[i] == g[i%6]) cnt[2]++;
	}
	m = max({cnt[0], cnt[1], cnt[2]});
	cout << m << "\n";
	for (int i = 0; i < 3; i++) {
		if (cnt[i] == m) {
			if (i == 0) cout << "Adrian";
			else if (i == 1) cout << "Bruno";
			else cout << "Goran";
			cout << "\n";
		}
	}
	return 0;
}
