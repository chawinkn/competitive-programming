#include <bits/stdc++.h>
using namespace std;

set<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, cnt=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (s.find(k) == s.end()) {
			s.insert(k);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
