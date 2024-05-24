#include <bits/stdc++.h>
using namespace std;

int n, m, k;
bool p[9];

void permu(int set, vector<int> ans) {
	if (ans.size() == n) {
		for (auto i : ans) cout << i << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!ans.size() && p[i+1]) continue;
		if (set&(1<<i)) continue;
		ans.push_back(i+1);
		permu(set|(1<<i), ans);
		ans.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> k;
		p[k] = true;
	}
	permu(0, {});
	return 0;
}