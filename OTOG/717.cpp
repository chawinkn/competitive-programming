#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
    return gcd(b, a%b);    
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q, n;
	cin >> q;
	while (q--) {
		cin >> n;
		int cnt=0;
		vector<int> ans;
		for (int i = 1; i <= n; i++) {
			if (gcd(i, n) == 1) {
				cnt++;
				ans.push_back(i);
			}
		}
		cout << cnt << "\n";
		for (auto i : ans) cout << i << " ";
		cout << "\n";
	}
	return 0;
}