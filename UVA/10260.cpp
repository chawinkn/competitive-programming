#include <iostream>
using namespace std;

int main() {
    int temp, digit[26]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
    string s;
    while (cin >> s) {
        string ans;
        for (int i = 0; s[i] != '\0'; i++) {
            temp = digit[s[i]-'A'];
            if (temp != digit[s[i-1]-'A'] || i == 0) {
                if (temp != 0) {
                    ans += ('0'+temp);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

