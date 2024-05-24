#include <bits/stdc++.h>
using namespace std;

int arr[3];

int main() {
	string s;
	for (int i = 0; i < 3; i++) cin >> arr[i];
	cin >> s;
	sort(arr, arr+3);
	for (auto i : s) {
		if (i == 'A') cout << arr[0];
		else if (i == 'B') cout << arr[1];
		else cout << arr[2];	
		cout << " ";
	}
	return 0;
}
