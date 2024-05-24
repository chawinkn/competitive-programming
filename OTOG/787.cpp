#include <bits/stdc++.h>
using namespace std;

map<string,int> mp;
int cnt[100009][19];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, q, num, a;
	string s;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s >> num;
		mp[s] = i;
		for (int j = 0; j < num; j++) {
			cin >> a;
			cnt[i][a]++;
		}
	}
	while (q--) {
		cin >> s;
		int idx=mp[s];
		for (int i = 1; i <= m; i++) {
			cout << cnt[idx][i] << " ";
		}
		cout << "\n";
	}
	return 0;
}