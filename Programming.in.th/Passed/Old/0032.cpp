#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr+n);
	if (arr[0] == 0) {
		for (int i = 1; i < n; i++) {
			if (arr[i] != 0) {
				swap(arr[0], arr[i]);
				break;	
			}
		}
	}
	for (int i = 0; i < n; i++) cout << arr[i];
	return 0;	
}
