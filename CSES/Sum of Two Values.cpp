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
	int i=0, j=n-1;
	while (i < j) {
		if (a[i].f+a[j].f == x) {
			cout << a[i].s << " " << a[j].s;
			return 0;
		}
		if (a[i].f+a[j].f > x) j--;
		else i++;
	}
	cout << "IMPOSSIBLE";
	return 0;
}