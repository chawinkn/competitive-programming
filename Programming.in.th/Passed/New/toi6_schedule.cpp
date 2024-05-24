#include <bits/stdc++.h>
using namespace std;

bool ans[500009];
vector<tuple<int,int,int>> arr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, m, s, f, cnt=0;
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s >> f;
		arr.push_back({s, 1, i});
		arr.push_back({f+1, 0, i});  
	}
	sort(arr.begin(), arr.end());
	for (auto [x, s, idx] : arr) {
		if (s && cnt < k) {
			ans[idx] = true;
			cnt++;
		}
		else if (!s && ans[idx]) cnt--;
	}
	while (m--) {
		int x;
		cin >> x;
		cout << (ans[x] ? "Y" : "N") << " ";
	}
	return 0;
}
