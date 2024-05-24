#include <bits/stdc++.h>
using namespace std;

int k, a, b;

void permutation(int w, int l, string s) {
	if (w == k || l == k) {
		for (char i : s) cout << i << " ";
		cout << "\n";
		return;
	}
	permutation(w+1, l, s+"W");
	permutation(w, l+1, s+"L");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k >> a >> b;
	permutation(a, b, "");
	return 0;
}
