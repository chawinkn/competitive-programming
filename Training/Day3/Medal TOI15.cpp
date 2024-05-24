#include <bits/stdc++.h>
using namespace std;

// Greedy

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> t(n), h(n);
	for (int i = 0; i < n; i++) cin >> t[i];
	for (int i = 0; i < n; i++) cin >> h[i];
	sort(t.begin(), t.end());
	sort(h.begin(), h.end());
	vector<int> temp(n);
	for (int i = 0; i < n; i++) temp[i] = t[i]+h[n-i-1];
	sort(temp.begin(), temp.end());
	cout << temp[n-1]-temp[0];
	return 0;
}