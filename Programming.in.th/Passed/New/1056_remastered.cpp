#include <bits/stdc++.h>
using namespace std;

int arr[2007];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, x=0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr+n);
	for (int i = n-1; i >= 0; i-=k) x += arr[i];
	cout << x;
	return 0;
}