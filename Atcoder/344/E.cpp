#include <bits/stdc++.h>
using namespace std;

list<int> l;
map<int,list<int>::iterator> m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q, a, t, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> a;
    	l.push_back(a);
    	m[a] = --l.end();
	}
	cin >> q;
	while (q--) {
		cin >> t >> x;
		if (t == 1) {
			cin >> y;
			auto it = m[x];
			it++;
			l.insert(it, y);
			it--;
			m[y] = it;
		}
		else l.erase(m[x]);
	}
	for (auto i : l) cout << i << " ";
    return 0;
}