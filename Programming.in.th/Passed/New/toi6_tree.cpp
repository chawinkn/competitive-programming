#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, u, v;
	for (int q = 0; q < 5; q++) {
		cin >> n;
		vector<pair<int,int>> g1, g2;
		for (int i = 0; i < n-1; i++) {
			cin >> u >> v;
			g1.push_back({min(u, v), max(u, v)});
		}
		for (int i = 0; i < n-1; i++) {
			cin >> u >> v;
			g2.push_back({min(u, v), max(u, v)});
		}
		sort(g1.begin(), g1.end());
		sort(g2.begin(), g2.end());

		bool check=true;
		for (int i = 0; i < n-1; i++) {
			if (g1[i] != g2[i]) {
				check = false;
				break;
			}
		}
		if (check) cout << "Y";
		else cout << "N";
	}
	return 0;
}
