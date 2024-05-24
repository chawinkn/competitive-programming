#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a, b;
    while (cin >> a >> b) {	
		string s = b+'#'+a;
		int n=s.length();
		vector<int> pi(n);
	    for (int i = 1, j = 0; i < n; i++) {
	        while (j > 0 && s[j] != s[i]) j = pi[j - 1];
	        if (s[i] == s[j]) j++;
	        pi[i] = j;
	    }
		int ans = 0;
		for (auto i : pi) {
		    if (i == b.length()) ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}