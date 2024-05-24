#include <bits/stdc++.h>
using namespace std;
 
vector<int> arr;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, w, ans=1e9;
	cin >> n;
	n *= 2;
	for (int i = 0; i < n; i++) {
		cin >> w;
		arr.push_back(w);	
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int cnt=0, now=0, f;
			for (int k = 0; k < n; k++) {
				if (k == i || k == j) continue;
				
				cnt++;
				if (cnt == 1) f = arr[k];
				else {
					now += arr[k]-f;
					cnt = 0;
				}
			}
			ans = min(ans, now);
		}
	}
	cout << ans;
	return 0;
}