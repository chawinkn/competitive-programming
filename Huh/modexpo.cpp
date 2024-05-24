#include <bits/stdc++.h>
using namespace std;

int mod(int a, int b, int c) {
	if (a == 0) return 1;
	if (b == 1) return a % c;
	int temp=mod(a, b/2, c);
	if (b%2 == 0) return (temp * temp) % c;
	return ((temp * temp) % c * a%c) % c;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << mod(a, b, c);
	return 0;
}