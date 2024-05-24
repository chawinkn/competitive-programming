#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int,int>> p(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;	
		p[i] = {x, y};
	}
	sort(p.begin(), p.end(), cmp);
	int mx=0;
	for (auto [x,y] : p) {
		if (y >= mx) {
			mx = y;
			cout << x << " " << y << "\n";
		}
	}
	return 0;
}