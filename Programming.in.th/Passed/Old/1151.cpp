#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, h;
	cin >> n >> h;
	arr.push_back(h);
	for (int i = 1; i < n; i++) {
		cin >> h;
		if (arr.back() < h) {
			arr.push_back(h);
		}
		else {
			auto it = lower_bound(arr.begin(), arr.end(), h);
			*it = h;
		}
	}
	cout << arr.size();
	return 0;
}
