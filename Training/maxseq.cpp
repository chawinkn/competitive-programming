#include <bits/stdc++.h>
using namespace std;

int a[2509];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int l=1, L=1, R=1, sum=0, mx=0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		if (sum > mx) {
			mx = sum;
			L = l, R = i;
		}
		if (sum <= 0) {
			sum = 0;
			l = i+1;
		}
	}
	if (mx == 0) cout << "Empty sequence";
	else {
		for (int i = L; i <= R; i++) cout << a[i] << " ";
		cout << "\n" << mx;
	}
	return 0;
}