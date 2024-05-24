#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	cin >> s;
	string ans;
	bool found=false;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '|') {
			if (!found) found = true;
			else found = false;
			continue;
		}
		if (!found) cout << s[i];
	}
	return 0;
}