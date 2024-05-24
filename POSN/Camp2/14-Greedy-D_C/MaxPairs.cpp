#include <bits/stdc++.h>
using namespace std;

int cnt1[26], cnt2[26];

int main() {
	int n, ans=0;
	string s, t;
	cin >> n >> s >> t;
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') ans++;
		else cnt1[s[i]-'a']++;
		if (t[i] == '?') ans++;
		else cnt2[t[i]-'a']++;
	}
	for (int i = 0; i < 26; i++) {
		ans += min(cnt1[i], cnt2[i]);
	}
	if (ans > n) cout << n;
	else cout << ans;
	// cout << ans << " " << q;
	return 0;
}