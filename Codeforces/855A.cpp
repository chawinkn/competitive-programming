#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	unordered_set<string> m;
	while (n--) {
		cin >> s;
		if (m.find(s) == m.end()) {
			cout << "NO\n";
			m.insert(s);
		}
		else cout << "YES\n";
	}
	return 0;
}