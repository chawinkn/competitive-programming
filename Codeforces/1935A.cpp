#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void solve() {
	int c=1;
	for (int i = 0; i < s.size()/2; i++) {
		if (s[i] < s[s.size()-i-1]) break;
		if (s[i] > s[s.size()-i-1]) {
			c = 0;
			break;
		}
	}
	if (c) cout << s << "\n";
	else {
		string r = s;
		reverse(r.begin(), r.end());	
		cout << r << s << "\n";
	}
}

int main () {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		solve();
	}
	return 0;
}