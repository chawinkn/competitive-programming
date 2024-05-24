#include <bits/stdc++.h>
using namespace std;

map<vector<int>, int> m;
vector<int> arr;

int main() {
	int n, p, a;
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		vector<int> temp;
		for (int j = 0; j < p; j++) {
			cin >> a;
			temp.push_back(a);
		}
		m[temp] = i;
	}
	for (int j = 0; j < p; j++) {
		cin >> a;
		arr.push_back(a);
	}
	if (m.find(arr) != m.end()) {
		cout << m[arr];
		return 0;
	}
	for (auto it : m) {
		vector<int> temp=it.first;
		for (int i = 0; i < temp.size(); i++) temp[i] = abs(temp[i]-arr[i]);
		if (m.find(temp) != m.end() && it.second != m[temp]) {
			cout << min(it.second, m[temp]) << " " << max(it.second, m[temp]);
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
