#include <bits/stdc++.h>
using namespace std;
 
int arr[]={1,2,3,4,5,6,7,8,9,0};
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		int ans=0, idx=0;
		
		for (auto i : s) {
			int num=i-'0', now=arr[idx];
			if (num == 0) num = 10;
			if (now == 0) now = 10;
			ans += abs(num-now)+1;
			idx = num-1;
		}
		cout << ans << "\n";
	}
	return 0;
}