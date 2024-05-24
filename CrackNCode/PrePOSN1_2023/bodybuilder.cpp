#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int ans[29], s[29], w[29];

bool cmp(pair<int,int> a, pair<int,int> b) {
	if (a.f == b.f) return a.s < b.s;
	return a.f > b.f;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i] >> w[i];

	for (int i = 1; i < (1<<n); i++) {
		vector<pair<int,int>> arr;
		for (int j = 0; j < n; j++) {
			if (i & (1<<j)) arr.push_back({s[j], w[j]});
		}
		sort(arr.begin(), arr.end(), cmp);
		int k=arr.size(), canAdd=1;
		for (int j = 0; j < k-1; j++) {
			if (arr[j].f >= arr[j+1].f && arr[j].s <= arr[j+1].s) {
				canAdd = 0;
				break;
			}
		}
		if (canAdd) ans[k]++;
	}
	while (m--) {
		cin >> x;
		cout << ans[x] << "\n";
	}
	return 0;
}
