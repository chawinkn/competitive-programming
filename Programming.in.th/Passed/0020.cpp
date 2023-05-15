#include <bits/stdc++.h>
using namespace std;

int main() {
	int sum, num, x=0, m=0;
	for (int i = 0; i < 5; i++) {
		sum = 0;
		for (int j = 0; j < 4; j++) {
			cin >> num;	
			sum += num;
		}
		if (sum > m) {
			m = sum;
			x = i+1;
		}
	}
	cout << x << " " << m;
	return 0;
}
