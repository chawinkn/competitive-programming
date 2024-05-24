#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		int now=0, cnt[29]={0};
		for (auto i : s) {
			if (!cnt[i-'a']) now++;
			cnt[i-'a']++;
		}
		int ans=0;
		reverse(s.begin(), s.end());
		for (auto i : s) {
			if (cnt[i-'a']) cnt[i-'a']--;
			ans += now;
			if (!cnt[i-'a']) now--;
		}
		cout << ans << "\n";
	}
	return 0;
}