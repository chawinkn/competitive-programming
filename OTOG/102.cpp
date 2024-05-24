#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, m;
	char o;
	cin >> h >> m;
	if (m - 45 >= 0) {
		cout << h << " " << m - 45;
	}
	else {
		if (h == 0) {
			cout << 23 << " ";
	    }
	    else {
	    	cout << h - 1 << " ";
		}
		cout << m + 15; // 60 - 45 + m
	}
	return 0;
}
