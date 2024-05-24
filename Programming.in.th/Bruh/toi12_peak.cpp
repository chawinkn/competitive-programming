#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

// 95/100 points -> Bruh

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, l=0, m, r;
	cin >> n >> k >> m;
	for (int i = 1; i < n; i++) {
		cin >> r;
		if (m > l && m > r) ans.push_back(m);
		l = m;
		m = r;
	}
	if (m > l) ans.push_back(m);
	
	if (ans.size() == 0) {
		cout << -1;
		return 0;	
	}
	
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	int s = ans.size();
	if (s < k) {
		for (int i = 0; i < s && k > 0; i++, k--) cout << ans[i] << "\n";
	}
	else {
		for (int i = s-1; i >= 0 && k > 0; i--, k--) cout << ans[i] << "\n";
	}
	return 0;
}
