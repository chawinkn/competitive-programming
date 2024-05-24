#include <bits/stdc++.h>
using namespace std;

double X1[100009], X2[100009], Y1[100009], Y2[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<double,double>> v;
	for (int i = 1; i <= n; i++) {
		cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
		double m1=Y1[i]/X1[i], m2=Y2[i]/X2[i];
		v.push_back({max(m1, m2), min(m1, m2)});
	}
	sort(v.begin(), v.end());
	int cnt=0; 
	double e=-1;
	for (auto [r,l] : v) {
		if (l > e) {
			e = r;
			cnt++;
		}
	}
	cout << n-cnt;
	return 0;
}