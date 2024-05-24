#include <bits/stdc++.h>
using namespace std;

int main() {
	string n;
	int t=0, e=0, s=0;
	cin >> n;
	for (int i = 0; i < n.length()-1; i+=2) {
		t = (t%3+(n[i]-'0')%3+(n[i+1]-'0'))%3;
		s += n[i]-n[i+1];
		e = (e%11+s%11)%11;
	}
	cout << t << " " << e;
	return 0;
}
