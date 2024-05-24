#include <bits/stdc++.h>
using namespace std;

int arr[2509];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, l=1, ml=1, mr=1, sum=0, mx=INT_MIN;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        if (sum < 0) {
            sum = 0;
            l = i;
        }
        sum += arr[i];
        if (sum > mx) {
            mx = sum;
            ml = l;
            mr = i;
        }
    }
    if (mx <= 0) cout << "Empty sequence";
    else {
        for (int i = ml; i <= mr; i++) cout << arr[i] << " ";
        cout << "\n" << mx;
    }
    return 0;    
}
