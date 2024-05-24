#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++, k++) {
			k %= 26;
			cout << (char)('A'+k);
		}
		cout << "\n";
	}
	return 0;
}
