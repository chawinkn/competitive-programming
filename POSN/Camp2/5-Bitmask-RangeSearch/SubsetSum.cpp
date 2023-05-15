#include <iostream>
#include <bitset>
using namespace std;

int arr[100001];

int main() {
    int n, x, sum;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;
    for (int i = 0; i < (1 << n); i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) sum += arr[j];    
        }
        if (sum == x) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}