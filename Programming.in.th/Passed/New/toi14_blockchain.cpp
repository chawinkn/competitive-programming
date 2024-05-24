#include <bits/stdc++.h>
using namespace std;

map<vector<pair<int,int>>,int> mp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, q, n, u, v;
	cin >> t >> q;
	while (t--) {
		cin >> n;
		vector<pair<int,int>> temp;
		for (int i = 0; i < n-1; i++) {
			cin >> u >> v;
			temp.push_back({min(u,v), max(u,v)});
		}
		sort(temp.begin(), temp.end());
		mp[temp]++;
	}
	while (q--) {
		cin >> n;
		vector<pair<int,int>> temp;
		for (int i = 0; i < n-1; i++) {
			cin >> u >> v;
			temp.push_back({min(u,v), max(u,v)});
		}
		sort(temp.begin(), temp.end());
		cout << mp[temp] << "\n";
	}
	return 0;
}