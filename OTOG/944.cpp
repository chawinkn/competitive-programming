#include <bits/stdc++.h>
using namespace std;

string s;
map<char,int> m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;
	int ans=0;
	for (auto i : s) {
		if (m.find(i) == m.end()) m[i] = 1;
		else m[i]++;
		ans = max(ans, m[i]);
	}
	cout << ans;
	return 0;
}
