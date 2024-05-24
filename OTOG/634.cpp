#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

map<vector<pii>,int> mp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, q;
	cin >> t >> q;
	while (t--) {
		int n;
		cin >> n;
		vector<pii> temp;
		for (int i = 0; i < n-1; i++) {
			int u, v;
			cin >> u >> v;
			temp.push_back({min(u, v), max(u, v)});
		}
		sort(temp.begin(), temp.end());
		mp[temp]++;
	}
	while (q--) {
		int n;
		cin >> n;
		vector<pii> temp;
		for (int i = 0; i < n-1; i++) {
			int u, v;
			cin >> u >> v;
			temp.push_back({min(u, v), max(u, v)});
		}
		sort(temp.begin(), temp.end());
		cout << mp[temp] << "\n";
	}
	return 0;
}