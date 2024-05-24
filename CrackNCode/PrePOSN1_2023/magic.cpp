#include <bits/stdc++.h>
using namespace std;

#define ll long long

int arr[1000009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q, n, k, a;
	cin >> q;
	while (q--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> arr[i];
		
		int l=0, visited[1000009]={0};
		ll cnt=0, ans=0;
		
		for (int i = 0; i < n; i++) {
			if (!visited[arr[i]]) cnt++;
			visited[arr[i]]++;
			
			while (cnt >= k) {
				ans += n-i;
				visited[arr[l]]--;
				if (!visited[arr[l]]) cnt--;
				l++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
