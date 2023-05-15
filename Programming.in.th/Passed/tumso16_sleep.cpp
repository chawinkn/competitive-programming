#include <bits/stdc++.h>
using namespace std;

int arr[100003];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, s, e, m=-1, t=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		arr[s]++;
		arr[e]--;
	}
	for (int i = 1; i <= 100000; i++) {
		arr[i] += arr[i-1];
		if (arr[i] > m) {
			m = arr[i];
			t = i;
		}
	}
	if (m == n) cout << "yes ";
	else cout << "no ";
	cout << t;
}
