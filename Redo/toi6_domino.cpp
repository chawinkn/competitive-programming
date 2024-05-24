#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<string> s) {
	if (n == 0) {
		for (auto i : s) cout << i << "\n";
		cout << "E\n";
		return;
	}
	s.push_back("--");
	solve(n-1, s);
	s.pop_back();
	if (n < 2) return;
	s.push_back("||");
	solve(n-2, s);
	s.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	solve(n, {});
	return 0;
}