#include <bits/stdc++.h>
using namespace std;

int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
string date[7]={"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};

int main() {
	int d, m, cnt;
	cin >> d >> m;
	cnt = d;
	for (int i = 0; i < m-1; i++) cnt += month[i];
	cout << date[cnt%7];
	return 0;
}
