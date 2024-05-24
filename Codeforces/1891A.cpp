#include <bits/stdc++.h>
using namespace std;
 
int arr[59];
int temp[]={1, 2, 4, 8, 16, 32};
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		for (int i = 1; i < n; i++) {
			if (arr[i] <= arr[i+1]) continue;
			int now=temp[lower_bound(temp, temp+6, i)-temp];
			int k=arr[i]-arr[i+1];
			for (int j = 1; j <= now; j++) arr[j] -= k;
		}
		bool pass=true;
		for (int i = 1; i <= n-1; i++) {
			if (arr[i] > arr[i+1]) {
				pass = false;
				break;
			}
		}
		if (pass) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}