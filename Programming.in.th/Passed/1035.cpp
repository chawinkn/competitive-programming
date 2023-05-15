#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, num, sum, p;
	cin >> n;
	m = n;
	while (1 == 1) {
		num = m;
		sum = 0;
		while (num != 0) {
			sum *= 10;
			sum += num%10;
			num /= 10;
		}
		if (sum == m) {
			p = 1;
			for (int i = 2; i <= sqrt(m); i++) {
				if (m%i == 0) {
					p = 0;
					break;	
				}
			}
			if (p) {
				cout << m;
				break;
			}
		}
		m++;
	}
	return 0;
}
