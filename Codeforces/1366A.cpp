#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	long long int a, b, temp;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		if (a > b) {
			temp = a;
			a = b;
			b = temp;
		}
		if (a*2 <= b) {
			cout << a << "\n";
		}
		else {
			cout << (a+b)/3 << "\n";
		}
	}
	return 0;
}