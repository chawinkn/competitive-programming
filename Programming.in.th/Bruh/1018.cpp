#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, x=0, y=0;
	string c, d="E";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c >> k;
		if (c == "LT") {
			if (d == "N") d = "W";
			else if (d == "E") d = "N";
			else if (d == "S") d = "E";
			else if (d == "W") d = "S";
		}
		else if (c == "RT") {
			if (d == "N") d = "E";
			else if (d == "E") d = "S";
			else if (d == "S") d = "W";
			else if (d == "W") d = "N";
		}
		else if (c == "BW") {
			if (d == "N") d = "S";
			else if (d == "E") d = "W";
			else if (d == "S") d = "N";
			else if (d == "W") d = "E";
		}
		if (d == "N") y += k;
		else if (d == "E") x += k;
		else if (d == "W") x -= k;
		else if (d == "S") y -= k;
	}
	if (x > -50000 && x < 50000 && y > -50000 && y < 50000) {
		cout << x << " " << y << "\n";
		cout << d;
	}
	else {
		cout << "DEAD";
	}
	return 0;
}
