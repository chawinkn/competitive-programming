#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	string name;
	unordered_map<string,int> m;
	while (n--) {
		cin >> name;
		if (m.find(name) == m.end()) {
			cout << "OK\n";
			m[name] = 1;
		}
		else {
			cout << name << m[name] << "\n";
			m[name]++;
		}
	}
	return 0;
}