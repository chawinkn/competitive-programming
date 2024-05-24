#include <bits/stdc++.h>
using namespace std;

int arr[100003];

int main() {
	int n, w, cnt=0;
	cin >> n >> w;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr+n);
	for (int i = 0; i < n; i++) {
		if (w >= arr[i]) {
			// cout << w << " " << arr[i] << "\n";
			w -= arr[i];
			cnt++;
		}
	}
	cout << cnt;
}