#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, a=INT_MIN, b=INT_MAX;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		a = max(k, a);
		b = min(k, b);
	}
	cout << a << "\n" << b;
	return 0;
}
