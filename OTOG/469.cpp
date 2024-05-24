#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n >> s;
	string S=s+s;
	vector<int> temp;
	for (int i = 1; i <= n; i++) {
		if (n%i == 0) temp.push_back(i);
	}
	for (auto i : temp) {
		if (n%i == 0) {
			if (S.substr(i, n) == s) {
				cout << i;
				break;
			}
		}
	}
	return 0;
}