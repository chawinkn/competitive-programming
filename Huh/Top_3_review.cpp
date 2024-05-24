#include <bits/stdc++.h>
using namespace std;

vector<pair<double,string>> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	double x;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> s;
		v.push_back({x, s});
	}
	sort(v.begin(), v.end());
	for (int i = n-1; i >= max(n-3, 0); i--) cout << v[i].second << "\n";
    return 0;
}
