#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<pair<int,char>> arr;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, a, b, cnt=0, ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr.push_back({a, 's'});
		arr.push_back({b, 'e'});
	}
	sort(arr.begin(), arr.end());
	for (auto i : arr) {
		if (i.s == 's') cnt++;
		else cnt--;
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
