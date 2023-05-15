#include <bits/stdc++.h>
using namespace std;

int arr[19][19], n, dx=0, dy=0;

int connected(int i, int j) {
    int e = 0;
    if (i+1 < n && arr[i][j] == arr[i+1][j]) {
        dy = 1;
        e++;
    }
    if (i-1 >= 0 && arr[i][j] == arr[i-1][j]) {
        dy = -1;
        e++;
    }
    if (j+1 < n && arr[i][j] == arr[i][j+1]) {
        dx = 1;
        e++;
    }
    if (j-1 >= 0 && arr[i][j] == arr[i][j-1]) {
        dx = -1;
        e++;
    }
    return e;
}
int main() {
    int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (connected(i, j) == 2) {
                if (connected(i+dy, j) == 1) {
                    if (connected(i, j+dx) == 1) {
                        cnt++;
                    }
                }
            }
            // Set back to default
            dx = 0;
            dy = 0;
        }
    }
    cout << cnt;
    return 0;
}
