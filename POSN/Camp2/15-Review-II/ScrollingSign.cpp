#include <bits/stdc++.h>
using namespace std;

int calOverlap(string a, string b) {
	string s = b+'#'+a;
	int n=s.length();
	int i=1, j=0, lps[n]={0};
	while (i < n) {
		if (s[i] == s[j]) {
			lps[i] = j+1;
			i++, j++;
		}
		else if (j == 0) {
			lps[i] = 0;
			i++;
		}
		else j = lps[j-1];
	}
	return lps[n-1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int k, n;
	cin >> k >> n;
	string s1, s2;
	int ans=n*k;
	cin >> s1;
	for (int i = 1; i < n; i++) {
		cin >> s2;
		ans -= calOverlap(s1, s2);
		s1 = s2;
	}
	cout << ans << "\n";
	return 0;
}