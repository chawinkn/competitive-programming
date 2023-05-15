#include <iostream>
using namespace std;

int main() {
    int n, a, b, check;
    while (cin >> n) {
        int found[3001]={0};
        cin >> a;
        for (int i = 0; i < n-1; i++) {
            cin >> b;
            found[abs(a-b)] = 1;
            a = b;
        }
        int jolly = 1;
        for (int i = 1; i <= n-1; i++) {
            if (!found[i]) {
                jolly = 0;
                break;
            }
        }
        if (jolly) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
    return 0;
}
