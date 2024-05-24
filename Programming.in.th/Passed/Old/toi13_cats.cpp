#include <bits/stdc++.h>
using namespace std;

int s[2000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long int l=0, r=2e31, m;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	while (l < r) {
		m = (l+r)/2;
		int c=1, j;
		for (int i = 0; i < n; i++) {
			if (s[i] > m) {
				j = i+1;
				while (s[j] <= m) j++;
				if (s[i] == s[j]) i = j;
				else {
					c = 0;
					break;
				}
			}
		}
		if (c) r = m;
		else l = m+1;
	}
	cout << l;
	return 0;
}
