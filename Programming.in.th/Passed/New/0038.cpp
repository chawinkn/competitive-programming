#include <bits/stdc++.h>
using namespace std;

string s;
set<string> ss;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		cin >> s;
		ss.insert(s);
	}
	for (auto i : ss) cout << i << "\n";
	return 0;
}