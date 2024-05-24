#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

map<int,int> mp;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, q, a, k, x;
	cin >> n >> m >> q;
	while (m--) {
		cin >> a >> k;
		mp[a]++; mp[a+k]--;
	}
	for (auto i : mp) {
		if (i.s%2 == 0) continue;
		v.push_back(i.f);		
	}
	while (q--) {
		cin >> x;
		if (x < v.front()) cout << v.front()-1 << "\n";
		else if (x >= v.back()) cout << n-v.back()+1 << "\n";
		else {
			int idx=upper_bound(v.begin(), v.end(), x)-v.begin();
			cout << v[idx]-v[idx-1] << "\n";
		}
	}
	return 0;
}
