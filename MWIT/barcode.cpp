#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	int ans=0, cnt=0;
	cin >> s;
	for (auto i : s) {
		if (i == '0') cnt++;
		else if (i == '1' && cnt) {
			ans++;
			cnt = 0;
		}
	}
	if (cnt) ans++;
	cout << ans;
	return 0;
}
