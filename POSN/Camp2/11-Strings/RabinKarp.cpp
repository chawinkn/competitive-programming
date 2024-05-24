#include <bits/stdc++.h>
using namespace std;

string text, pattern;

long long int base=67, d=1, ht=0, hp=0, q=10e9+7;

int main() {
	int n, m;
	cin >> text >> pattern;
	n = text.length();
	m = pattern.length();
	// text = kanoon
	// pattern = oon
	for (int i = m-1; i >= 0; i--) {
		ht += d*(text[i]-'a') % q;
		hp += d*(pattern[i]-'a') % q;
		d *= base;
	}
	d /= base;
	if (ht == hp) {
		cout << "Found";
	}
	else {
		for (int i = 1; i <= n-m; i++) {
			ht = (base*((ht-d*(text[i-1]-'a')))+(text[i+m-1]-'a')) % q;
			cout << ht << " " << hp << "\n";
			if (ht == hp) {
				cout << "Found";
				return 0;
			}
		}
		cout << "Not Found";
	}
	return 0;
}
