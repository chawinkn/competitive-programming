#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	int n=a.length(), m=b.length();
	int mn=min(n, m);
	for (int sz = mn; sz >= 1; sz--) {
		vector<int> cnta(29), cntb(29);
		set<vector<int>> s;
		for (int i = 0; i < sz; i++) cnta[a[i]-'A']++;
		s.insert(cnta);
		for (int i = 1; i+sz-1 < n; i++) {
			cnta[a[i-1]-'A']--, cnta[a[i+sz-1]-'A']++;
			s.insert(cnta);
		}
		for (int i = 0; i < sz; i++) cntb[b[i]-'A']++;
		if (s.find(cntb) != s.end()) {
			cout << sz;
			break;
		}
		for (int i = 1; i+sz-1 < m; i++) {
			cntb[b[i-1]-'A']--, cntb[b[i+sz-1]-'A']++;
			if (s.find(cntb) != s.end()) {
				cout << sz;
				return 0;
			}
		}
	}
	return 0;
}