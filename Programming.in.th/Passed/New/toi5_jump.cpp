#include <bits/stdc++.h>
using namespace std;

int arr[30009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int ans=0;
	for (int i = 0; i < n; i++) {
		int idx=upper_bound(arr, arr+n, arr[i]+k)-arr-i-1;
		ans = max(ans, idx);
	}
	cout << ans;
	return 0;
}
