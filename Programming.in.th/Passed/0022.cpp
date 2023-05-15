#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, w;
	cin >> n;
	k = n/2;
	w = n;
	if (n%2 == 0) w--;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < w; j++) {
			if (i+j == w/2 || j-i == w/2) cout << "*";
			else cout << "-";
		}
		cout << "\n";
	}
	for (int i = n-k-1; i >= 0; i--) {
		for (int j = 0; j < w; j++) {
			if (i+j == w/2 || j-i == w/2) cout << "*";
			else cout << "-";
		}
		cout << "\n";
	}
	return 0;
}
