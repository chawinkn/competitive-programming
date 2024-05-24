#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int arr[100009];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	long long int num;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<pair<long long int,int>> arr;
		for (int i = 0; i < n; i++) {
			cin >> num;
			arr.push_back({num, i});
		}
		sort(arr.begin(), arr.end());
		long long int sum=0;
		int ans[n], dp[n];
		dp[0] = 1;
		sum = arr[0].first;
		for (int i = 1; i < n; i++) {
			dp[i] = dp[i-1];
			if (sum >= arr[i].first) dp[i]++;
			sum += arr[i].first;
		}
		sum = 0;
		for (int i = 0; i < n; i++) {
			ans[arr[i].second] = dp[i];
//			sum += arr[i].first;
//			if (sum >= arr[i+1].first) {
//				long long int tmp = sum+arr[i+1].first;
//				int cnt=0;
//				for (int j = i+1; j < n; j++) {
//					if (tmp >= arr[j+1].first) cnt++;
//					else break;
//					tmp += arr[j+1].first;
//				}
//				ans[arr[i].second] = i+cnt+1;
//			}
//			else ans[arr[i].second] = i;
		}
		for (auto i : ans) cout << i << " ";
		cout << "\n";
	}
	return 0;
}


