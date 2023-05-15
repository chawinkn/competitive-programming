#include <bits/stdc++.h>
using namespace std;

pair<int,int> arr[507];

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr+k);
    for (int i = 0; i < k; i++) {
//        for (int j = i+1; j < k; j++) {
//            cout << abs(arr[j].first-arr[i].first)+abs(arr[j].second-arr[i].second) << "\n";
//        }
//        cout << "\n";
    }
    return 0;
}
