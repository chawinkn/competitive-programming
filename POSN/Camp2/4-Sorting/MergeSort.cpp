#include <bits/stdc++.h>
using namespace std;

int arr[100003];

void Merge(int l, int m, int r) {
    int a[r-l+1];
    int i=l, j=m+1, k=0;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            a[k++] = arr[i++];
        }
        else {
            a[k++] = arr[j++];
        }
    }
    while (i <= m) {
        a[k++] = arr[i++];
    }
    while (j <= r) {
        a[k++] = arr[j++];
    }
    for (int i = l; i <= r; i++) {
        arr[i] = a[i-l];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
//    for (int i = 1; i <= n; i*=2) {
//        for (int j = 1; j <= n; j+=2*i) {
//            cout <<
//        }
//        cout << "\n";
//    }
    for (int i = 1; i < 2; i*= 2) {
        for (int j = 1; j <= n; j+=2*i) {
            Merge(j, j+i-1, j+2*i-1);
        }
    }
    for (int i = 1; i <= n; i++) cout << arr[i] << " ";
    return 0;
}
