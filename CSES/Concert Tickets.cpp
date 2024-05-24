#include <bits/stdc++.h>
using namespace std;

multiset<int> tickets;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, h, t;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> h;
		tickets.insert(h);
	}
	for (int i = 0; i < m; i++) {
		cin >> t;
		auto it=tickets.upper_bound(t);
		if (it == tickets.begin()) cout << "-1\n";
		else {
			it--;
			cout << *it << "\n";
			tickets.erase(it);
		}
	}
	return 0;
}