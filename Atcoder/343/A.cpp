#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	for (int i = 0; i <= 9; i++) {
		if (i == a+b) continue;
		cout << i; 
		break;
	}
	return 0;
}