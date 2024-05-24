#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, cnt = 0;
	cin >> n;
	while (n > 0) {
		if (n >= 10) {
			cnt += 3000;
			n -= 15;
		}
		else if (n >= 4) {
			cnt += 1500;
			n -= 5;
		}
		else if (n >= 2) {
			cnt += 800;
			n -= 2;
		}
		else {
			cnt += 500;
			n--;
		}
	}
    cout << cnt;
	return 0;
}
