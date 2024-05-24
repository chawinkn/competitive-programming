#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<pair<int,int>> t;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		t.push_back({a, 1});
		t.push_back({b, -1});
	}
	sort(t.begin(), t.end());
	int cnt=0, ans=0;
	for (auto i : t) {
		cnt += i.s;
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}