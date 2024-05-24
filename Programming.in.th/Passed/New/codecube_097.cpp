#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			cout << i << " ";
			if (i*i == n) continue;
			arr.push_back(i);	
		}
	}
	for (int i = arr.size()-1; i >= 0; i--) cout << n/arr[i] << " ";
	return 0;
}
