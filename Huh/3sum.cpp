#include <bits/stdc++.h>
using namespace std;

int a[100009];

int main() {
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			cout << a[i];
			return 0;	
		}
	}
	sort(a, a+n);
	int l=0, r=n-1;
	while (l < r) {
		int sum=a[l]+a[r];
		if (sum == x) {
			cout << a[l] << " " << a[r];
			return 0;
		}
		else if (sum < x) l++;
		else r--;
	}
	for (int i = 0; i < n-2; i++) {
		int l=i+1, r=n-1;
		while (l < r) {
			int sum=a[i]+a[l]+a[r];
			if (sum == x) {
				cout << a[i] << " " << a[l] << " " << a[r];
				return 0;
			}
			else if (sum < x) l++;
			else r--;
		}
	}
	return 0;
}