#include <iostream>
using namespace std;

int arr[103][103], sum[103][103], s, m=-10e8;

int main() {
    int r, c;
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> arr[i][j];
            sum[i][j] = sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
            if (arr[i][j] == 0) sum[i][j]++;
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            for (int k = i; k <= r; k++) {
                for (int l = j; l <= c; l++) {
                    s = sum[k][l]-sum[k][j-1]-sum[i-1][l]+sum[i-1][j-1];
                    if (s == (k-i+1)*(l-j+1)) m = max(m, s);
                }
            }
        }
    }
    cout << m;
    return 0;
}
