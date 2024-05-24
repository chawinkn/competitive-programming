#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, ans=1;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr.begin(), arr.end());
		arr[0]++;
		for (int i = 0; i < n; i++) ans *= arr[i];
		cout << ans << "\n";
	}
	return 0;
}