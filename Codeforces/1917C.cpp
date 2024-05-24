#include <bits/stdc++.h>
using namespace std;
 
int arr[2009], v[100009];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, k, d;
	cin >> t;
	while (t--) {
		cin >> n >> k >> d;
		for (int i = 0; i < n; i++) cin >> arr[i];
		for (int i = 0; i < k; i++) cin >> v[i];
		int ans=0;
		for (int i = 0; i < min(d, 2*n); i++) {
			int cnt=0;
			for (int j = 0; j < n; j++) cnt += (arr[j] == j+1);
			ans = max(ans, cnt+(d-i-1)/2);
			for (int j = 0; j < v[i%k]; j++) arr[j]++;
		}
		cout << ans << "\n";
	}
	return 0;
}