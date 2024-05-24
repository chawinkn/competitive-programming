#include <bits/stdc++.h>
using namespace std;

#define M 1e6

vector<int> cnt(1000009, 1),  arr[509];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q, x, y, d;
	cin >> q;
	for (int i = 2; i <= M; i++) {
		for (int j = i; j <= M; j+=i) cnt[j]++;
	}
	for (int i = 1; i <= M; i++) arr[cnt[i]].push_back(i);
	while (q--) {
		cin >> x >> y >> d;
		int s = lower_bound(arr[d].begin(), arr[d].end(), x) - arr[d].begin();
		int e = upper_bound(arr[d].begin(), arr[d].end(), y) - arr[d].begin();
		cout << e-s << "\n";
	}
	return 0;
}
