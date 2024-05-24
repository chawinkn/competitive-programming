#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	string in;
	cin >> t;
	while (t--) {
		cin >> in;
		int n=in.length(), B=0, b=0;
		stack<pair<char,int>> u, l;
		for (int i = 0; i < n; i++) {
			if (in[i] == 'B' && !u.empty()) {
				in[u.top().second] = '.';
				u.pop();
			}
			else if (in[i] == 'b' && !l.empty()) {
				in[l.top().second] = '.';
				l.pop();
			}
			else {
				if (isupper(in[i])) u.push({in[i], i});
				else l.push({in[i], i});
			}
		}
		for (int i = 0; i < n; i++) {
			if (in[i] == '.' || in[i] == 'b' || in[i] == 'B') continue;
			cout << in[i];
		}
		cout << "\n";
	}
	return 0;
}