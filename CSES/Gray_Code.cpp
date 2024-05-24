#include <bits/stdc++.h>
using namespace std;

int n;

void code(int l, string s) {
	if (l == n) {
		cout << s[0];
		for (int i = 1; i < n; i++) cout << (s[i]-'0'+s[i-1]-'0')%2;
		cout << "\n";
		return;	
	}
	code(l+1, s+"0");
	code(l+1, s+"1");
}

int main() {
	cin >> n;
	code(0, "");
	return 0;
}
