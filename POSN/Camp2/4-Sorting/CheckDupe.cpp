#include <bits/stdc++.h>
using namespace std;

int arr[100003];

int main() {
    int n, num, cnt;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    num = arr[0];
    cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == num) cnt++;
        else {
            if (cnt >= n/3) {
                cout << num << " ";
            }
            num = arr[i];
            cnt = 1;
        }
    }
    return 0;
}
