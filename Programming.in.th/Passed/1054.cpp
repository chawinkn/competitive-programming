#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

pair<pair<int,int>,int>  arr[100009];

int main() {
	int n, ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i].f.f >> arr[i].f.s >> arr[i].s;
	sort(arr, arr+n);
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int a=arr[j].f.f-arr[i].f.f, b=arr[j].f.s-arr[i].f.s, c=arr[j].s+arr[i].s;
			if (a >= 20) break;
			if (a*a+b*b < c*c) ans++;
		}
	}
	cout << ans;
	return 0;
}
