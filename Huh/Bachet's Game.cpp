#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	while (cin >> n) {
		int m;
		cin >> m;
		vector<int> s(m+1);
		for (int i = 1; i <= m; i++) cin >> s[i];
		bool dp[n+1]={false};
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i >= s[j] && !dp[i-s[j]]) dp[i] = true;
			}
		}
		cout << (dp[n] ? "Stan wins" : "Ollie wins") << "\n";
	}
	return 0;
}