#include <bits/stdc++.h>
using namespace std;
 
int arr[209];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, t;
	cin >> t;
	while (t--) {
		int ans=0;
		cin >> n;
		for (int i = 0; i < 2*n; i++) cin >> arr[i];
		sort(arr, arr+2*n);
		for (int i = 0; i < n-1; i++) ans += arr[i+1]-arr[i]+arr[n+i+1]-arr[n+i];
		cout << ans << "\n";
		for (int i = 0; i < n; i++) cout << arr[i] << " " << arr[n+i] << "\n";
//		1 5 10 15
//		10 10 20 20 30 30
	}
	return 0;
}