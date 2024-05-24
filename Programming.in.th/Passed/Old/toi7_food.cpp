#include <bits/stdc++.h>
using namespace std;

int n, m, j, p[9];

void permutation(int l, string s, int v[]) {
	if (l == n) {
		for (char i : s) cout << i << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			if (l == 0 && p[i]) continue;
			v[i] = 1;
			string temp=s;
			temp += '0'+i;
			permutation(l+1, temp, v);
			v[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> j;
		p[j] = 1;	
	}
	int v[9]={0};
	permutation(0, "", v);
	return 0;
}
