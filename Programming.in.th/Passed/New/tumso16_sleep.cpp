#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<pair<int,int>> arr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, s, e, cnt=0, mx=-1, ans;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		arr.push_back({s, 's'});
		arr.push_back({e, 'e'});
	}
	sort(arr.begin(), arr.end());
	for (auto i : arr) {
		if (i.s == 's') cnt++;
		else cnt--;
		if (cnt > mx) {
			mx = cnt;
			ans = i.f;
		}
	}
	if (mx == n) cout << "yes ";
	else cout << "no ";
	cout << ans;
	return 0;
}
