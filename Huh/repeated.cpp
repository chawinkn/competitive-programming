#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n=s.length();
	vector<int> temp;
	for (int i = 1; i*i <= n; i++) {
		if (n%i != 0) continue;
		temp.push_back(i);
		if (i != n/i) temp.push_back(n/i);
	}
	sort(temp.begin(), temp.end());
	for (auto sz : temp) {
		string p=s.substr(0, sz);
		bool valid=true;
		for (int j = sz; j < n; j += sz) {
			if (s.substr(j, sz) != p) {
				valid = false;
				break;
			}
		}
		if (valid) {
			cout << p << " " << sz << "\n";
			break;
		}
	}
	return 0;
}