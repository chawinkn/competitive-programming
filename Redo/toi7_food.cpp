#include <bits/stdc++.h>
using namespace std;

bool P[9];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;	
		P[p] = true;
	}
	vector<int> f(n);
	for (int i = 0; i < n; i++) f[i] = i+1;
	do {
		if (P[f[0]]) continue;
		for (auto i : f) cout << i << " ";
		cout << "\n";
	} while (next_permutation(f.begin(), f.end()));
	return 0;
}