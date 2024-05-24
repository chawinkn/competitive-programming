#include <bits/stdc++.h>
using namespace std;

int arr[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, q, x;
	cin >> t;
	while (t--) {
		cin >> n >> q;
		vector<int> temp;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		while (q--) {
			cin >> x;
			if (temp.empty() || temp.back() > x) temp.push_back(x);
		}
		for (int i = 1; i <= n; i++) {
			for (auto j : temp) {
				if (arr[i]%(1<<j) == 0) arr[i] |= 1<<(j-1);
			}
		}
		for (int i = 1; i <= n; i++) cout << arr[i] << " ";
		cout << "\n";
	}
	return 0;
}
