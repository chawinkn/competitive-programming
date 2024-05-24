#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	string in;
	cin >> t;
	while (t--) {
		cin >> in;
		for (int i = 1; i <= 8; i++) {
			if (i == in[1]-'0') continue;
			cout << in[0] << i << "\n";
		}
		for (int i = 1; i <= 8; i++) {
			if ((char)('a'+i-1) == in[0]) continue;
			cout << (char)('a'+i-1) << in[1] << "\n";
		}
	}
	return 0;
}