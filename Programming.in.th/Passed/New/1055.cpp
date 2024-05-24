#include <bits/stdc++.h>
using namespace std;

int ans[23];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, x, idx=0;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		cin >> x;
		idx += x;
		idx %= arr.size();
		ans[i%k] += arr[idx];
		arr.erase(arr.begin()+idx);
	}
	for (int i = 0; i < k; i++) cout << ans[i] << "\n";
	return 0;
}
