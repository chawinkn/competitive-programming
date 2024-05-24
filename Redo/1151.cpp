#include <bits/stdc++.h>
using namespace std;

vector<int> LIS;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		int h;
		cin >> h;
		auto it=lower_bound(LIS.begin(), LIS.end(), h);
		if (it == LIS.end()) LIS.push_back(h);
		else *it = h;
	}
	cout << LIS.size();
	return 0;
}