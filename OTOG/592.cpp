#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, cmd, tmp, a[1000];
	cin >> n >> cmd;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) {
				tmp = a[j];
				a[j] = a[i];
				a[i] = tmp;
			}
		}	
	}
	if (cmd == 0) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";	
		}
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			cout << a[i] << " ";	
		}
	}
	return 0;
}
