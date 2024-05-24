#include <bits/stdc++.h>
using namespace std;

vector<int> lis;
int a[100009], b[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = n; i >= 1; i--) {
		if (a[i] > b[i]) continue;
		auto it=upper_bound(lis.begin(), lis.end(), b[i]-a[i]);
		if (it == lis.end()) lis.push_back(b[i]-a[i]);
		else *it = b[i]-a[i];
	}
	cout << lis.size();
	return 0;
}