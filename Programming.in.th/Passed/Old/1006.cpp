#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int d[6]={1, 2, 3, 5, 4, 6};
		cin >> s;
		for (auto j : s) {
			if (j == 'F') {
				swap(d[1], d[5]);
				swap(d[1], d[3]);
				swap(d[0], d[1]);
			}
			else if (j == 'B') {
				swap(d[0], d[1]);
				swap(d[1], d[5]);
				swap(d[3], d[5]);
			}
			else if (j == 'L') {
				swap(d[0], d[4]);
				swap(d[4], d[5]);
				swap(d[2], d[5]);
			}
			else if (j == 'R') {
				swap(d[0], d[4]);
				swap(d[0], d[2]);
				swap(d[2], d[5]);
			}
			else if (j == 'C') {
				swap(d[1], d[2]);
				swap(d[1], d[4]);
				swap(d[3], d[4]);
			}
			else if (j == 'D') {
				swap(d[3], d[4]);
				swap(d[1], d[4]);
				swap(d[1], d[2]);
			}
		}
		cout << d[1] << " ";
	}
	return 0;
}
