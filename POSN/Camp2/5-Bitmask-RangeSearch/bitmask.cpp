#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int n = 42; // 00101010
    int m = 1; // 000001
    // << a (multiply by a)
    // >> a (divide by a)
    cout << (3 << 1) << "\n"; // 00001100
    cout << (3 << 2) << "\n"; // 00011000
    cout << (3 << 3) << "\n"; // 00110000
    cout << ((3 << 3) >> 1) << "\n";
    return 0;
}