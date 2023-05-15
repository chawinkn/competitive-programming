#include <bits/stdc++.h>
using namespace std;

int arr[1000003], l[1000003];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		l[i] = max(l[i-1], arr[i]);
	}
	for (int i = n; i >= 1; i--) {
		arr[i] = max(arr[i+1], arr[i]);
	}
	for (int i = 1; i < n; i++) {
		cout << min(l[i], arr[i+1]) << " ";
	}
	return 0;
}

