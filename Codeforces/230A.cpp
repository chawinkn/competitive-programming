#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
 
pair<int,int> arr[1001];
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int s, n, t;
	cin >> s >> n;
	for (int i = 0; i < n; i++) cin >> arr[i].f >> arr[i].s;
	sort(arr, arr+n);
	for (int i = 0; i < n; i++) {
		if (s > arr[i].f) {
			s += arr[i].s;
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}