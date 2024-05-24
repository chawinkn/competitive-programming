#include <bits/stdc++.h>
using namespace std;

int arr[3]={1, 0, 0};

//void trik(int *p1, int *p2) {
//	int temp=*p1;
//	*p1 = *p2;
//	*p2 = temp;
//}

int main() {
	string s;
	cin >> s;
	for (auto i : s) {
		if (i == 'A') swap(arr[0], arr[1]);
		else if (i == 'B') swap(arr[1], arr[2]);
		else swap(arr[0], arr[2]);
	}
	for (int i = 0; i < 3; i++) if (arr[i] == 1) cout << i+1;
	return 0;
}
