#include <bits/stdc++.h>
using namespace std;

// Math

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int d;
	cin >> d;
	bool isPrime=true;
	for (int i = 2; i*i <= d; i++) {
		if (d%i == 0) {
			isPrime = false;
			break;
		}
	}
	cout << ((isPrime && d >= 2) ? "Yes" : "No");
	return 0;
}