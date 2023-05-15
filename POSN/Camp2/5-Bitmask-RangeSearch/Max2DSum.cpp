#include <iostream>
using namespace std;

int arr[103][103], sum[103][103], m=-10e8;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            sum[i][j] = sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= n; l++) {
                    m = max(m, sum[k][l]-sum[k][j-1]-sum[i-1][l]+sum[i-1][j-1]);
                }
            }
        }
    }
    cout << m;
    return 0;
}
