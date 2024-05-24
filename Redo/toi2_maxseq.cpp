#include <bits/stdc++.h>
using namespace std;

int a[2509];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int mx=0, sum=0, l=1, r=1, L, R;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (sum+a[i] > a[i]) {
			sum += a[i];
			r = i;
		}
		else {
			sum = a[i];
			l = i;
			r = i;
		}
		if (sum > mx) {
			mx = sum;
			L = l;
			R = r;
		}
	}
	if (mx == 0) {
		cout << "Empty sequence";	
		return 0;
	}
	for (int i = L; i <= R; i++) cout << a[i] << " ";
	cout << "\n" << mx;
	return 0;
}