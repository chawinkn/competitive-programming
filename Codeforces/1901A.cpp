#include <bits/stdc++.h>
using namespace std;

int arr[59];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		int mx=0;
		for (int i = 0; i < n; i++) cin >> arr[i];		
		for (int i = 0; i < n-1; i++) mx = max(mx, arr[i+1]-arr[i]);
		cout << max({mx, arr[0], 2*(x-arr[n-1])}) << "\n";
	}
	return 0;
}