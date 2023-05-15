#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<pair<int,int>> arr, ans;

bool cmp1(pair<int,int> a, pair<int,int> b) {
	if (a.f != b.f) return a.f > b.f;
	return a.s < b.s;
}

bool cmp2(pair<int,int> a, pair<int,int> b) {
	if (a.f != b.f) return a.f < b.f;
	return a.s > b.s;
}

int main() {
	int n, x, y;
	cin >> n;
	while (n--) {
		cin >> x >> y;
		arr.push_back({x, y});
	}
	sort(arr.begin(), arr.end(), cmp1);
	int m=0;
	for (auto i : arr) {
		if (i.s >= m) {
			m = i.s;
			ans.push_back({i.f, i.s});
		}
	}
	sort(ans.begin(), ans.end(), cmp2);
	for (auto i : ans) cout << i.f << " " << i.s << "\n";
	return 0;
}
