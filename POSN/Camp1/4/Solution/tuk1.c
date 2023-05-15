#include <stdio.h>

int main() {
  int n, m=-1;
  scanf("%d", &n);
  int h[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &h[i]);
    if (h[i] > m) m = h[i];
  }
  for (int i = m; i >= 1; i--) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < h[j]; k++) {
        if (i <= h[j]) {
          printf("* ");
        }
        else {
          printf("  ");
        }
      }
    }
    printf("\n");
  }
  return 0;
}
  