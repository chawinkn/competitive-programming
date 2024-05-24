#include <bits/stdc++.h>
using namespace std;

double w[100003];
pair<double,pair<double,double>> arr[100003];

int main() {
	int n;
	double m, v;
	long long int sumW=0, sumV=0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 0; i < n; i++) {
		cin >> v;
		arr[i] = {-v/w[i], {w[i], v}};
	}
	cin >> m;
	sort(arr, arr+n);
	for (int i = 0; i < n && sumW <= m; i++) {
		double x, currW=arr[i].second.first, currV=arr[i].second.second;
		if (sumW+currW <= m) x = 1;
		else x=(m-sumW)/currW;
		sumW += x*currW;
		sumV += x*currV;
	}
	cout << sumV;
}