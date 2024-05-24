#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
	if (a.f.f == b.f.f) return a.f.s < b.f.s;
	return a.f.f < b.f.f;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, l, r;
	vector<pair<pair<int,int>,int>> arr;
	vector<int> end;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		arr.push_back({{l, r}, i});
		end.push_back(r);
	}
	sort(arr.begin(), arr.end(), cmp);
	for (auto i : arr) {
		cout << i.f.f << " " << i.f.s << " " << i.s << "\n";
	}
	sort(end.begin(), end.end());
	int ans[n], mx=0;
	for (auto i : arr) {
		int idx=upper_bound(end.begin(), end.end(), i.f.s)-end.begin();
		cout << idx << " : ";
		ans[i.s] = idx;
		end.erase(end.begin()+idx);
		for (auto j : end) cout << j << " ";
		cout << "\n";
	}
	cout << mx << "\n";
	for (int i = 0; i < n; i++) cout << ans[i] << " "; 
	return 0;
}n