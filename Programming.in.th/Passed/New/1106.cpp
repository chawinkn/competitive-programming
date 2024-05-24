#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, now=0;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) a[i] = i+1;
	while (a.size() > 1) {
		now = (now+k-1)%a.size();
		k = a[now];
		a.erase(a.begin()+now);
	}
	cout << a[0];
	return 0;	
}