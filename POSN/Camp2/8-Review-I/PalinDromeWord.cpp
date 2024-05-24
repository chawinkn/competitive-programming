#include <iostream>
#include <string.h>
using namespace std;

string arr[10002];
string s;

int main() {
    int i=0;
    while (cin >> s) {
        arr[i] = s;
        i++;
    }
    int n=i;
    for (i = 0; i < n/2; i++) {
        if (arr[i] != arr[n-i-1]) {
            cout << "F";
            return 0;
        }
    }
    cout << "T";
    return 0;
}