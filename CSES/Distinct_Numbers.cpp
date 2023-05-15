#include <bits/stdc++.h>
using namespace std;

int arr[200001];

int main() {
	int n, cnt=1;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr+n);
	for (int i = 1; i < n; i++) if (arr[i] != arr[i-1]) cnt++;
	cout << cnt;
	return 0;
}
