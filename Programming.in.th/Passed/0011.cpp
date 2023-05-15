#include <bits/stdc++.h>
using namespace std;

int mod[42];

int main() {
	int num, r, cnt=0;
	for (int i = 0; i < 10; i++) {
		cin >> num;
		r = num%42;
		if (!mod[r]) {
			mod[r] = 1;	
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
