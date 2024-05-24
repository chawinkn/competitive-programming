#include <bits/stdc++.h>
using namespace std;

int arr[21][21];

int main() {
	int n, m, s, h, cnt=0;
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			arr[i][j] += s*i;	
		}
	}
	for (int j = 0; j < m; j++) {
		h = arr[0][j];
		for (int i = 1; i < n; i++) {
			if (arr[i][j] <= h) cnt++;
			h = max(h, arr[i][j]);
		}
	}
	cout << n*m-cnt;
	return 0;
}
