#include <bits/stdc++.h>
using namespace std;

#define ll long long

// 75/100

ll base=98765431;
unordered_map<ll,vector<int>> hsh;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int k, m;
	cin >> k >> m;
	for (int i = 1; i <= k; i++) {
		string s;
		cin >> s;
		ll hash=0, b=1;
		for (int j = m-1; j >= 0; j--) {
			hash += s[j]*b;
			if (j > 0) b *= base;
		}
		hsh[hash].push_back(i);
	}
	int n;
	cin >> n;
	while (n--) {
		int l;
		string s;
		cin >> l >> s;
		bool found=false;
		ll first=0, b=1;
		for (int i = m-1; i >= 0; i--) {
			first += s[i]*b;
			if (i > 0) b *= base;
		}
		ll hash = first;
		set<int> ans;
		for (int i = 0; i <= l-m; i++) {
			if (hsh.find(hash) != hsh.end()) {
				found = true;
				for (auto j : hsh[hash]) ans.insert(j);
			}
			hash -= s[i]*b;
			hash *= base;
			hash += s[i+m];
		}
		if (!found) cout << "OK";
		else for (auto i : ans) cout << i << " ";
		cout << "\n";
	}
	return 0;
}