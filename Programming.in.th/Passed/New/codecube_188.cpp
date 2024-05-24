#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> mp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q, l, r, c;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
    	cin >> c;
    	mp[c].push_back(i);
	}
    while (q--) {
    	cin >> l >> r >> c;
    	auto L = lower_bound(mp[c].begin(), mp[c].end(), l);
    	auto R = upper_bound(mp[c].begin(), mp[c].end(), r);
    	cout << R-L << "\n";
	}
    return 0;
}