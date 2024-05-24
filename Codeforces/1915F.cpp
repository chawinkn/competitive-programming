#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int a, b;
		vector<pair<int,int>> arr;
		vector<int> end;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			arr.push_back({a, b});
			end.push_back(b);
		}
		sort(arr.begin(), arr.end());
		sort(end.begin(), end.end());
		long long ans=0;
		for (auto i : arr) {
			int idx=lower_bound(end.begin(), end.end(), i.second)-end.begin();
			ans += idx;
			end.erase(end.begin()+idx);
		}
		cout << ans << "\n";
	}
	return 0;
}