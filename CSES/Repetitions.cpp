#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int cnt=1, ans=1;
	cin >> s;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == s[i-1]) cnt++;
		else cnt = 1;
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
