#include <bits/stdc++.h>
using namespace std;

int arr[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q, b;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr+1, arr+n+1);
	for (int i = 1; i <= n; i++) arr[i] += arr[i-1];
	while (q--) {
		cin >> b;
		int idx = upper_bound(arr+1, arr+n+1, b)-arr;
		cout << idx-1 << "\n";
	}
	return 0;
}
