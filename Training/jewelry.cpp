#include <bits/stdc++.h>
using namespace std;

// 37/100

#define ll long long

string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n >> s;
	s = ' '+s;
	ll ans=0;
	if (n <= 5000) {
		for (int i = 1; i <= n; i++) {
			int sum=0, best=0;
			for (int j = i; j <= n; j++) {
				if (s[j] == 'T') sum++;
				else sum = 0;
				best = max(best, sum);
				ans += best;
			}
		}
	}
	else {
		ll last=0;
		int i=1;
		while (s[i] != 'T') i++;
		for (; i <= n; i++) {
			if (s[i] == 'T') {
				ans += last+i;
				last += i;
			}
			else ans += last;
		}
	}
	cout << ans;
	return 0;
}