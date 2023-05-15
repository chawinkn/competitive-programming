#include <bits/stdc++.h>
using namespace std;

int arr[2009];

int main() {
	int n, k, ans=0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr+n);
	for (int i = n-1; i >= 0; i-=k) ans += arr[i];
	cout << ans;
	return 0;
}
