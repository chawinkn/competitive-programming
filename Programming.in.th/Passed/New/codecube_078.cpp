#include <bits/stdc++.h>
using namespace std;

int arr[7];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int x, sum=0, founded=0;
	cin >> x;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < 5; i++) {
		if (sum-arr[i] == x) {
			arr[i] = 0;
			founded = 1;
			break;
		}
	}
	if (founded || sum == x) for (int i = 0; i < 5; i++) cout << arr[i] << " ";
	else cout << -1;
	return 0;
}
