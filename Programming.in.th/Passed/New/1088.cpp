#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<pair<int,int>> arr;
char c;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, a, b, t;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr.push_back({a, 1});
		arr.push_back({b+1, -1});
	}
	arr.push_back({1, 0});
	arr.push_back({n+1, 0});
	sort(arr.begin(), arr.end());
	
	cin >> c;
	if (c == 'R') t = 0;
	else if (c == 'G') t = 1;
	else t = 2;
	
	int ans=0, sum=0;
	for (int i = 0; i < arr.size()-1; i++) {
		sum += arr[i].s;
		ans += ((3+t-sum%3)%3)*(arr[i+1].f-arr[i].f);
	}
	cout << ans;
	return 0;
}
