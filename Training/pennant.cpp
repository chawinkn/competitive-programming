#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, h[10009], tree[10009], cnt[10009];
map<int,int> mp;

void update(int i, int v) {
	for (; i <= n; i+=i&-i) tree[i] += v;
}

int query(int i) {
	int res=0;
	for (; i; i-=i&-i) res += tree[i];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		h[i] *= -1;
		mp[h[i]] = 0;
	}
	int idx=0;
	for (auto& i : mp) i.second = ++idx;
	// cnt[i] = count number greater than h[i] to the left
	for (int i = 1; i <= n; i++) {
		cnt[i] = query(mp[h[i]]-1);
		update(mp[h[i]], 1);
	}
	memset(tree, 0, sizeof(tree));
	ll ans=0;
	for (int i = n; i >= 1; i--) {
		ans += cnt[i]*query(mp[h[i]]-1);
		update(mp[h[i]], 1);
	}
	cout << ans;
	return 0;
}

// 6
// 10 7 12 5 8 9

// 11

// 5
// 10 20 25 15 5

// 0