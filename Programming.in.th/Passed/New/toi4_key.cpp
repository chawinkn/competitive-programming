#include <bits/stdc++.h>
using namespace std;

string a, x, b;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int l, k;
	cin >> l >> k >> a >> b >> x;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < l; j++) {
			vector<int> temp={a[j], x[i], b[j]};
			sort(temp.begin(), temp.end());
			x[i] = temp[1];
		}
	}
	cout << x;
	return 0;	
}
