#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	vector<pair<int,int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].f;
		a[i].s = i+1;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n-2; i++) {
		int l=i+1, r=n-1;
		while (l < r) {
			int sum=a[i].f+a[l].f+a[r].f;
			if (sum == x) {
				cout << a[i].s << " " << a[l].s << " " << a[r].s;
				return 0;
			}
			else if (sum < x) l++;
			else r--;
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}