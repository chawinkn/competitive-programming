#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, num, m=2e9, M=-2e9;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		m = min(m, num);
		M = max(M, num);
	}
	cout << m << "\n" << M;
	return 0;
}
