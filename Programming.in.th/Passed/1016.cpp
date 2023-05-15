#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	double x=0, y=0;
	while (cin >> s) {
		if (s == "*") break;
		double n = 0;
		vector<char> d;
		for (auto i : s) {
			if (i >= '0' && i <= '9') {
				n *= 10;
				n += i-'0';
			}
			else d.push_back(i);
		}
		if (d.size() == 2) n /= sqrt(2);
		for (auto i : d) {
			if (i == 'N') y += n;
			else if (i == 'E') x += n;
			else if (i == 'W') x -= n;
			else if (i == 'S') y -= n;
		}	
	}
	printf("%.3f %.3f\n%.3f", x, y, sqrt(x*x+y*y));
	return 0;
}
