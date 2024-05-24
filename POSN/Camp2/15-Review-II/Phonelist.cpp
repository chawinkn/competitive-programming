#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	sort(s.begin(), s.end());
	for (int i = 0; i < n-1; i++) {
		if (s[i].length() > s[i+1].length()) continue;
		if (s[i] == s[i+1].substr(0, s[i].length())) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}