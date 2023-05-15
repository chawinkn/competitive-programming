#include <cstdio>
#include <stack>
using namespace std;

stack<int> plates;

void add_plate(int s) {
    if (plates.empty()) {
        printf("yes\n");
        plates.push(s);
    }
    else if (s <= plates.top()) {
        printf("yes\n");
        plates.push(s);
    }
    else printf("no\n");
}
void remove_plate() {
    if (!plates.empty()) {
        printf("%d\n", plates.top());
        plates.pop();
    }
    else printf("-1\n");
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        int c,s;
        scanf("%d",&c);
        if(c == 1) {
            scanf("%d", &s);
            add_plate(s);
        } else {
            remove_plate();
        }
    }
    return 0;
}
