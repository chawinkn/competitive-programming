#include <bits/stdc++.h>
using namespace std;

void lps(string p) {
	int m=p.length();
	vector<int> lps(m);
	int i=1, j=0;
	while (i < m) {
		if (p[i] == p[j]) {
			lps[i] = j+1;
			i++, j++;
		}
		else if (j == 0) i++;
		else j = lps[j-1];
	}
	for (auto i : p) cout << i << " ";
	cout << "\n";
	for (auto i : lps) cout << i << " ";
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	lps(a+'#'+b);
	lps(b+'#'+a);
	return 0;
}