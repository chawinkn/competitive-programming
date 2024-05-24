#include <bits/stdc++.h>
using namespace std;

int arr[100007];

int mss(int l, int r) {
    if (l >= r) return arr[l];
    int m=(l+r)/2, ml=INT_MIN, mr=INT_MIN, sum;
    sum = 0;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        ml = max(ml, sum);
    }
    sum = 0;
    for (int i = m+1; i <= r; i++) {
        sum += arr[i];
        mr = max(mr, sum);
    }
    return max(max(mss(l, m), mss(m+1, r)), ml+mr);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cout << mss(1, n);
    return 0;
}