#include <bits/stdc++.h>
using namespace std;

vector<int> lis;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		auto it=lower_bound(lis.begin(), lis.end(), x);
		if (it == lis.end()) lis.push_back(x);
		else *it = x;
	}
	cout << lis.size();
	return 0;
}