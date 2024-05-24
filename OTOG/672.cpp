#include <bits/stdc++.h>
using namespace std;

map<vector<int>,int> mp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) arr[i] = i+1;
	int cnt=1;
	do {
		mp[arr] = cnt;
		cnt++;
	} while (next_permutation(arr.begin(), arr.end()));
	while (k--) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		cout << mp[a] << "\n";
	}
	return 0;
}