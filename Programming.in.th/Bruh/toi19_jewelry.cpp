#include <bits/stdc++.h>
using namespace std;

#define ll long long

string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n >> s;
	s = ' '+s;
	ll ans=0;
	for (int i = 1; i <= n; i++) {
		int sum=0, best=0;
		for (int j = i; j <= n; j++) {
			if (s[j] == 'T') sum++;
			else sum = 0;
			best = max(best, sum);
			ans += best;
		}
	}
	cout << ans;
	return 0;
}