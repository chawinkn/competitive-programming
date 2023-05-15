#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main() {
	int a=0, b=0, sum=0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];	
		sum += arr[i];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = i+1; j < 9; j++) {
			if (sum-arr[i]-arr[j] == 100) {
				a = i;
				b = j;
				break;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (i != a && i != b) {
			cout << arr[i] << "\n";	
		}
	}
	return 0;
}
