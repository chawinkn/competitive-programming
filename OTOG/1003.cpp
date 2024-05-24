#include <bits/stdc++.h>
using namespace std;

// 80/100

#define ll long long

const int M=1e9+7;

int a[100009];
ll C[2][10009];
map<int,vector<int>> mp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, q;
	cin >> n >> k >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]].push_back(i);
	}
	while (q--) {
		int l, r, c;
		cin >> l >> r >> c;
		int cnt=upper_bound(mp[c].begin(), mp[c].end(), r)-lower_bound(mp[c].begin(), mp[c].end(), l);
		if (cnt < k) {
			cout << "-1\n";
			continue;
		}
		if (k == 2) {
			cout << cnt*(cnt-1)/2 << "\n";
			continue;
		}
		for (int i = 0; i <= cnt; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0 || j == i) C[i%2][j] = 1;
				else C[i%2][j] = C[(i-1)%2][j]+C[(i-1)%2][j-1], C[i%2][j] %= M;
			}
		}
		cout << C[cnt%2][k] << "\n";
	}
	return 0;
}