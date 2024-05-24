#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	vector<int> a;
	while (cin >> n) a.push_back(n);
	reverse(a.begin(), a.end());
	for (auto i : a) cout << i << "\n";
	return 0;
}