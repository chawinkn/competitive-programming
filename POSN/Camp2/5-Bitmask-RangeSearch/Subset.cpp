#include <iostream>
#include <bitset>
using namespace std;

int arr[100001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < (1 << n); i++) { // Power Set (2^n)
        bitset<8> a(i);
        cout << a << "\n";
        for (int j = 0; j < n; j++) { // Permute
            bitset<8> b(1 << j);
            if (i & (1 << j)) {
                cout << b << " ";
                // cout << arr[j] << " ";
            }
        }
        cout << "\n\n";
    }
    return 0;
}