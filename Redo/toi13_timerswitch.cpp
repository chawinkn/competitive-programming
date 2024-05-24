#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll base=98765431;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	ll b=1, hash=0;
	for (int i = n-1; i >= 0; i--) {
		hash += s[i]*b;
		if (i > 0) b *= base;
	}
	ll hsh=hash;
	for (int i = 0; i < n; i++) {
		hsh -= s[i]*b;
		hsh *= base;
		hsh += s[i];
		if (hsh == hash) {
			cout << i+1;
			break;
		}
	}
	return 0;
}