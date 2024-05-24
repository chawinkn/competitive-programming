#include <bits/stdc++.h>
using namespace std;

set<int> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		int c;
		cin >> c;
		if (c == 0) {
			int x;
			cin >> x;
			s.insert(x);
		}
		else {
			int x, y;
			cin >> x >> y;
			int cnt=0;
			auto it=s.lower_bound(x);
			while (it != s.end()) {
				if (*it > y) break;
				s.erase(it++);
				cnt++;
			}
			cout << cnt << "\n";
		}
	}
	return 0;
}