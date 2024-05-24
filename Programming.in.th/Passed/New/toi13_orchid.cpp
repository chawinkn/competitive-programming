#include <bits/stdc++.h>
using namespace std;

vector<int> lis;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, h;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h;
		auto it=upper_bound(lis.begin(), lis.end(), h);
		if (it == lis.end()) lis.push_back(h);
		else *it = h;
	}
	cout << n-lis.size();
	return 0;
}