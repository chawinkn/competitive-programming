#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, num, c1 = 0, c2 = 0, tmp;
	cin >> n;
	int e[n], o[n];
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num % 2 == 0) {
			e[c1] = num;
			c1++;
		}	
		else {
			o[c2] = num;
			c2++;
		}
	}
	sort(e, e + c1);
	sort(o, o + c2);
	for (int i = 0; i < c1; i++) {
		cout << e[i] << " ";
	}
	for (int i = c2 - 1; i >= 0; i--) {
		cout << o[i] << " ";
	}
	return 0;
}
