#include <bits/stdc++.h>
using namespace std;

vector<int> lis;

int main() {
	int n, k;
	cin >> n;
	while (n--) {
		cin >> k;
		auto it = upper_bound(lis.begin(), lis.end(), k);
		if (it == lis.end()) lis.push_back(k);
		else *it = k;
	}
	cout << lis.size();
	return 0;
}
