#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	string s;
	cin >> n >> m >> s;
	int l=1, r=n;
	while (l < r) {
		int mid=l+(r-l+1)/2;
		bool check=false;
		map<string,int> cnt;
		for (int i = 0; i <= n-mid; i++) {
			if (++cnt[s.substr(i, mid)] >= m) {
				check = true;
				break;
			}
		}
		if (check) l = mid;
		else r = mid-1;
	}
	cout << l;
	return 0;
}