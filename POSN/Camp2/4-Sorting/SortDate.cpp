#include <bits/stdc++.h>
using namespace std;

pair<int,int> arr[100001];
char month[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

int main() {
    int n, m;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        string t;
        for (int j = 0; j < 3; j++) t += s[j];
        if (s[0] == 'J') {
            if (s[1] == 'a') m = 0;
            else if (s[2] == 'n') m = 5;
            else m = 6;
        }
        else if (s[0] == 'F') m = 1;
        else if (s[0] == 'M') {
            if (s[2] == 'r') m = 2;
            else m = 4;
        }
        else if (s[0] == 'A') {
            if (s[1] == 'p') m = 3;
            else m = 7;
        }
        else if (s[0] == 'S') m = 8;
        else if (s[0] == 'O') m = 9;
        else if (s[0] == 'N') m = 10;
        else m = 11;
        arr[i] = {-10*(s[3]-'0')-(s[4]-'0'), -m};
    }
    sort(arr, arr+n);
    for (int i = 0; i < n; i++) {
        printf("%s%02d\n", month[-arr[i].second], -arr[i].first);
    }
    return 0;
}
