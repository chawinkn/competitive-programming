#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

multiset<int> m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int k, n;
	cin >> k >> n;
	vector<pair<int,int>> t(k);
	for (int i = 0; i < k; i++) cin >> t[i].s >> t[i].f;
	sort(t.begin(), t.end());
	for (int i = 0; i < n; i++) m.insert(0);
	int ans=0;
	for (auto i : t) {
		auto it=m.upper_bound(i.s);
		if (it == m.begin()) continue;
		m.erase(--it);
		m.insert(i.f);
		ans++;
	}
	cout << ans;
	return 0;
}