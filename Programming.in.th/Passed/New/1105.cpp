#include <bits/stdc++.h>
using namespace std;

int arr[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr+n);
	cout << arr[n-k];
	return 0;
}
