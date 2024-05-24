#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int r, g, n;
	cin >> r >> g;
	for (int i = 1; i*i <= r; i++) {
		if (r%i == 0) {
			if (g%i == 0) ans.push_back({i, r/i});	
			if (g%(r/i) == 0 && i*i != r) ans.push_back({r/i, i});
		}
	}
	sort(ans.begin(), ans.end());
	for (auto i : ans) cout << i.first << " " << i.second << " " << g/i.first << "\n";
	return 0;
}
