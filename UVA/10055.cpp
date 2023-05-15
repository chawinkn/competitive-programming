#include <iostream>
#include <fstream>
using namespace std;

int main() {
//    ifstream cin("c:\\temp\\input.txt");
    long long int a, b;
    while (cin >> a >> b) {
        cout << abs(a-b) << "\n";
    }
    return 0;
}
