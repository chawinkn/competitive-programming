#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int a[3] = {0}, cnt = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'O') a[0]++;
		else if (s[i] == 'T') a[1]++;
		else if (s[i] == 'G') a[2]++;
		
		if (a[0] >= 1 && a[1] >= 1 && a[2] >= 1) {
			a[0]-=2;
			a[1]--;
			a[2]--;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
