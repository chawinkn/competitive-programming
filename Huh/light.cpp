#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n >> s;
	int ans=0;
	char state='0';
	for (int i = 0; i < n; i++) {
		if (s[i] == state) {
			state = (state == '0') ? '1' : '0';
			ans++;
		}
	}
//	0111010111
	
//	1000101000
//	1111010111
//	1111101000
//	1111110111
//	1111111000
//	1111111111
	cout << ans;
	return 0;
}