#include <bits/stdc++.h>
using namespace std;

int cnt[10001];

int main() {
	int n, num, m=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		cnt[num]++;
		m = max(m, cnt[num]);
	}
	for (int i = 1; i <= 10000; i++) {
		if (cnt[i] == m) cout << i << " ";
	}
	return 0;
}
