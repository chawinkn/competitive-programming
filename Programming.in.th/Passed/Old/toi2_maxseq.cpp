#include <bits/stdc++.h>
using namespace std;

int arr[2501];

int main() {
	int n, l, r, sum, m=INT_MIN;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			if (sum > m) {
				m = sum;
				l = i;
				r = j;
			}
		}
	}
	if (m > 0) {
		for (int i = l; i <= r; i++) cout << arr[i] << " ";
		cout << "\n" << m;
	}
	else cout << "Empty sequence";
	return 0;
}
