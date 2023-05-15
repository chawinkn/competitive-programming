#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	char o;
	cin >> a >> o >> b;
	int n = a.length()-1, m = b.length()-1;
	if (o == '*') {
		cout << "1";
		for (int i = 0; i < n+m; i++) cout << "0";
	}
	else {
		if (n == m) {
			cout << "2";
			for (int i = 0; i < max(n, m); i++) cout << "0";
		}
		else {
			cout << "1";
			for (int i = 0; i < max(n, m)-min(n, m)-1; i++) cout << "0";
			cout << "1";
			for (int i = 0; i < min(n, m); i++) cout << "0";
		}
	}
	return 0;
}
