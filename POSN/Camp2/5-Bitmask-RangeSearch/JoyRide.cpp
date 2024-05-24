#include <iostream>
using namespace std;

int arr[100003], m=-10e8, sum;

int main() {
    int n, l, r;
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    for (int i = 1; i <= n-1; i++) {
        for (int j = i; j <= n-1; j++) {
            sum = arr[j]-arr[i-1];
            if (sum >= m) {
                m = sum;
                l = i;
                r = j+1;
            }
        }
    }
    if (m > 0) cout << l << " " << r;
    else cout << 0;
    return 0;
}
