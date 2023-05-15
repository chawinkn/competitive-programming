#include <iostream>
#include <bitset>
using namespace std;

// i   6  5  4 3   2   1
//     1 1 0 1 1 0 1 0 1
// a = 0 1 0 0 1 0 0 0 1
// b = 1 0 0 1 0 0 1 0 0

bitset<32> a(0);
bitset<32> b(0);

int main() {
    int num, cnt=1;
    cin >> num;
    bitset<32> n(num);
    for (int i = 0; i < 32; i++) {
        if (n.test(i)) { // if bit[i] == 1
            if (cnt%2 == 1) a.set(i); // set a[i] to 1
            else b.set(i); // set b[i] to 1
            cnt++;
        }
    }
    cout << a.to_ulong() << " " << b.to_ulong();
    return 0;
}