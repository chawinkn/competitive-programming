#include <bits/stdc++.h>
using namespace std;

bool p[8000000]; // bool use less memory than int but it passed both lol

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, cnt=0;
	cin >> n;
	for (int i = 2; i < 8000000; i++) {
		if (!p[i]) {
			cnt++;
			if (cnt == n) {
				cout << i;
				break;
			}
			for (int j = 2*i; j < 8000000; j+=i) {
				p[j] = true;
			}
		}
	}
	return 0;
}

