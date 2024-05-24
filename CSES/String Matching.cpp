#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s, p;
	cin >> s >> p;
	int n=s.length(), m=p.length();
	int i=1, j=0;
	vector<int> lps(m);
	while (i < m) {
		if (p[i] == p[j]) {
			lps[i] = j+1;
			i++, j++;
		}
		else if (j == 0) i++;
		else j = lps[j-1];
	}
	i=0, j=0;
	int ans=0;
	while (i < n) {
		if (s[i] == p[j]) {
			i++, j++;
		}
		else if (j == 0) i++;
		else j = lps[j-1];
		if (j == m) ans++;
	}
	cout << ans;
	return 0;
}