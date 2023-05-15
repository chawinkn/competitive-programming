#include <bits/stdc++.h>
using namespace std;

int arr[100009];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr+n);
	if (n >= 3) {
		if (arr[0]+arr[1] > arr[n-1]) cout << "no";
		else cout << "yes";
	}
	else cout << "no";
	return 0;
}
