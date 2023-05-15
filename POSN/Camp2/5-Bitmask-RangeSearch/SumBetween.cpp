#include <iostream>
using namespace std;

int arr[1003], sum;

int main() {
    int n, l, h, cnt=0;
    cin >> n >> l >> h;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            sum = arr[j]-arr[i-1];
            if (sum >= l && sum <= h) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
