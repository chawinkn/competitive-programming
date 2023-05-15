#include <bits/stdc++.h>
using namespace std;

int main() {
	int i = 0;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		cout << s[i];
		if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') && s[i+1] == 'p' && s[i+2] == s[i]) i+=2;
	}
	return 0;
}
