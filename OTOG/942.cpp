#include <bits/stdc++.h>
using namespace std;

map<float,int> arr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	float mn, mx, k, v;
	cin >> n >> m;
	mn = -1;
	mx = n-2;
	for (float i = -1; i < n-1; i++) arr[i] = 0;
	string in;
	while (m--) {
		cin >> in;
		if (in == "pa") {
			for (auto i : arr) cout << i.second << " ";
			cout << "\n";
		}
		else if (in == "i") {
			cin >> k >> v;
			if (k < mn || k > mx) cout << "error\n";
			else {
				arr[k] = v;
				mn = min(mn, k);
				mx = max(mx, k);
			}
		}
		else if (in == "pi") {
			cin >> k;
			if (k < mn || k > mx) cout << "error\n";
			else {
				if (arr.find(k) != arr.end()) cout << arr[k] << "\n";
				else cout << "0\n";
			}
		}
	}
	return 0;
}
