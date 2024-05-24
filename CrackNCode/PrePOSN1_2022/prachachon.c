#include <stdio.h>
 
int main() {
    int q, x, ans[8]={0};
    char card[8][14];
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%s", card[i]);
        x = 0;
        for (int j = 0; j < 12; j++) {
            x += (13-j)*(card[i][j]-'0');
        }
        x %= 11;
        if (card[i][12]-'0' == (11-x)%10) {
            ans[i] = 1;
        }
    }
    for (int i = 0; i < q; i++) {
        if (ans[i]) printf("Y\n");
        else printf("N\n");
    }
}