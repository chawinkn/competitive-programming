#include <bits/stdc++.h>
using namespace std;

int tmp[10][10];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) cin >> tmp[i][j];
	}
	for (int k = 1; k <= n; k++) {
		int arr[10][10], r[10][10]={0}, c[10][10]={0}, check=1;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) cin >> arr[i][j];
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (arr[i][j] != tmp[i][j] && tmp[i][j] != 0) check = 0;
				if (!r[i][arr[i][j]] && !c[j][arr[i][j]]) {
					r[i][arr[i][j]] = 1;
					c[j][arr[i][j]] = 1;
				}
				else check = 0;
			}
		}
		if (check) cout << k << "\n";
	}
	cout << "END";
	return 0;
}
