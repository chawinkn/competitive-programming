#include <iostream>
using namespace std;

void search(int a, int b, int c) {
    for (int x = -100; x <= 100; x++) {
        for (int y = -100; y <= 100; y++) {
            for (int z = -100; z <= 100; z++) {
                if ((x+y+z == a) && (x*y*z == b) && (x*x+y*y+z*z == c)) {
                    cout << x << " " << y << " " << z << "\n";
                    return;
                }
            }
        }
    }
    cout << "No solution.\n";
}

int main() {
    int n, a, b, c;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        search(a, b, c);
    }
    return 0;
}