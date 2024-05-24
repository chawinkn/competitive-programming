#include <bits/stdc++.h>
using namespace std;

int arr[100003];
set<int> s;

int main() {
    int n, check=0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            for (int k = j+1; k < n; k++) {
                if (s.find(arr[i]*100+arr[j]*10+arr[k]) == s.end() && arr[i]+arr[j]+arr[k] == 0) {
                    s.insert(arr[i]*100+arr[j]*10+arr[k]);
                    check = 1;
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << "\n";
                }
            }
        }
    }
    if (!check) cout << 0;
    return 0;
}
