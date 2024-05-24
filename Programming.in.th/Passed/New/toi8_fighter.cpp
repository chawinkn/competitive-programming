#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int p;
	cin >> p;
	int n, pa=p, pb=p, ca=0, cb=0;
	for (int i = 0; i < 2*p; i++) {
		cin >> n;
		if (n%2 == 0) {
			ca++;
			cb = 0;
			if (ca >= 3) pb -= 3;
			else pb--;
		}
		else {
			cb++;
			ca = 0;
			if (cb >= 3) pa -= 3;
			else pa--;
		}
		if (pa <= 0) {
			cout << "1\n" << n;
			break;
		}
		else if (pb <= 0) {
			cout << "0\n" << n;
			break;
		}
	}
	return 0;
}
