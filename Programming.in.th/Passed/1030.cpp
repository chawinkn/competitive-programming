#include <bits/stdc++.h>
using namespace std;

pair<double, int> rice[100001];

int main() {
	int k, q, m, b, ii=0;
	double x, p;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> p >> q;
		rice[i] = {p/q, q};
	}
	sort(rice, rice+k);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b;		
		x = 0;
		while (b > 0) {
			if (rice[ii].second >= b) {
				x += rice[ii].first*b;
				rice[ii].second -= b;
				b = 0;
			}
			else {
				x += rice[ii].first*rice[ii].second;
				b -= rice[ii].second;
				rice[ii].second = 0;
				ii++;
			}
		}	
		printf("%.3f\n", x);
	}
	return 0;
}
