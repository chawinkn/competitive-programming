#include <bits/stdc++.h>
using namespace std;

int arr[100009];
double r[100009], t[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		r[i] = arr[i]/2.0+r[i-1];
	}
	for (int i = n; i >= 1; i--) {
		t[i] = arr[i]+t[i+1];
	}
	int roger=0, tony=0;
	for (int i = 1; i <= n; i++) {
		cout << r[i] << " " << t[i];
		if (t[i] <= r[i]) {
			cout << " TONY";
			tony++;
		}
		else {
			cout << " ROGER";
			roger++;
		}
		cout << "\n";
	}
	cout << roger << "\n" << tony << "\n";
	if (roger == tony) cout << "Roger and Tony";
	else if (roger > tony) cout << "Roger";
	else cout << "Tony";
	return 0;
}