#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if ((s.length() == 1 && s[0] == '2')|| (s[s.length()-1]-'0')%2 == 1) cout << "T\n";
		else if ((s[s.length()-1]-'0')%2 == 0) cout << "F\n";
	}
	return 0;
}
