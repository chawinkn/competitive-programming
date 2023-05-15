#include <iostream>
using namespace std;

int arr[10003], m=-10e6;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            m = max(m, arr[j]-arr[i-1]);
        }
    }
    if (m > 0) cout << m;
    else cout << -1;
    return 0;
}
