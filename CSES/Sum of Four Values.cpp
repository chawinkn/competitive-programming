#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
 
map<int,pair<int,int>> mp;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (mp.find(x-a[i]-a[j]) != mp.end()) {
				auto [k,l]=mp[x-a[i]-a[j]];
				cout << i+1 << " " << j+1 << " " << k << " " << l;
				return 0;
			}
		}
		for (int j = 0; j < i; j++) mp[a[i]+a[j]] = {i+1, j+1};
	}
	cout << "IMPOSSIBLE";
	return 0;
}
