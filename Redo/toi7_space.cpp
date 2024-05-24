#include <bits/stdc++.h>
using namespace std;

int d;

void solve(int n, string s) {
	if (n == d) {
		for (int i = n-1; i >= 0; i--) {
			if (s[i] == '0') {
				cout << s << " ";
				s[i] = '1';
				cout << s << "\n";
				s[i] = '0';
			}
		}
		return;
	}
	solve(n+1, s+"0");
	solve(n+1, s+"1");
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> d;
	solve(0, "");
	return 0;
}