#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q=5;
	while (q--) {
		int n;
		cin >> n;
		vector<pair<int,int>> t1, t2;
		int u, v;
		for (int i = 0; i < n-1; i++) {
			cin >> u >> v;
			t1.push_back({min(u, v), max(u, v)});
		}
		for (int i = 0; i < n-1; i++) {
			cin >> u >> v;
			t2.push_back({min(u, v), max(u, v)});
		}
		sort(t1.begin(), t1.end());
		sort(t2.begin(), t2.end());
		cout << (t1 == t2 ? "Y" : "N");
	}
	return 0;
}