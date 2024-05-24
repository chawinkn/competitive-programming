#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n == -1) break;
		int q=1, w=1, s=0, temp=2;
		for (int i = 1; i <= n; i++) {
			s = w;
			w = temp;
			temp = q+w+s;
		}
		cout << w << " " << temp << "\n";
	}
//	q = 1 -> w
//	w = 1 -> w, s
//	s = 0
//	
//	q = 1 -> w
//	w = 2 -> w, s, w, s
//	s = 1 -> w
//	
//	q = 1 -> w
//	w = 4 -> w, s, w, s, w, s, w, s
//	s = 2 -> w, w
	return 0;
}
